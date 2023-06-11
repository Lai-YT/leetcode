struct SnapshotArray {
  /// The index of the outer Vec corresponds to the index of the array.
  snapshots: Vec<Vec<(i32 /* snap_id */, i32 /* value */)>>,
  next_snap_id: i32,
}

impl SnapshotArray {
  fn new(length: i32) -> Self {
      Self {
          snapshots: vec![vec![(0, 0)]; length as usize],
          next_snap_id: 0,
      }
  }

  fn set(&mut self, index: i32, val: i32) {
      if let Some((ref snap_id, ref mut snap_val)) = self.snapshots[index as usize].last_mut() {
          // has change in the current snapshot, update the val
          if *snap_id == self.next_snap_id {
              *snap_val = val;
              return;
          }
      }
      self.snapshots[index as usize].push((self.next_snap_id, val))
  }

  fn snap(&mut self) -> i32 {
      self.next_snap_id += 1;
      self.next_snap_id - 1
  }

  fn get(&self, index: i32, target_snap_id: i32) -> i32 {
      let snapshots_of_index = &self.snapshots[index as usize];
      // x is the smallest one greater than target_snap_id.
      // It cannot be 0 since 0 is always held by snap_id 0, so safe to minus 1.
      let x =
          snapshots_of_index.partition_point(|(snap_id, _snap_val)| *snap_id <= target_snap_id);
      snapshots_of_index[x - 1].1
  }
}
