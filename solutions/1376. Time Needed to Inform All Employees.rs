impl Solution {
  pub fn num_of_minutes(n: i32, head_id: i32, manager: Vec<i32>, inform_time: Vec<i32>) -> i32 {
      // Cached table. The time an employee is informed.
      let mut informed_time = vec![-1; n as usize];
      informed_time[head_id as usize] = 0;
      let mut max_time: i32 = 0;
      for employee in 0..n {
          max_time = max_time.max(Self::get_informed_time(
              employee,
              &manager,
              &inform_time,
              &mut informed_time,
          ));
      }
      max_time
  }

  fn get_informed_time(
      employee: i32,
      manager: &Vec<i32>,
      inform_time: &Vec<i32>,
      informed_time: &mut Vec<i32>,
  ) -> i32 {
      // has cache
      if informed_time[employee as usize] != -1 {
          return informed_time[employee as usize];
      }
      // compute & add cache
      informed_time[employee as usize] = inform_time[manager[employee as usize] as usize]
          + Self::get_informed_time(
              manager[employee as usize],
              manager,
              inform_time,
              informed_time,
          );
      informed_time[employee as usize]
  }
}
