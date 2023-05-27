impl Solution {
  pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
      let mut dist1 = 0;
      let mut i = start;
      while i != destination {
          dist1 += distance[i as usize];
          i = (i + 1) % distance.len() as i32;
      }
      let mut dist2 = 0;
      // go another direction
      let mut j = destination;
      while j != start && dist2 < dist1 {
          dist2 += distance[j as usize];
          j = (j + 1) % distance.len() as i32;
      }

      dist1.min(dist2)
  }
}
