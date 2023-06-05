impl Solution {
  pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
      // trick: for slopes to be equal, we have delta(y1) / delta(x1) == delta(y2) / delta(x2).
      // To avoid the cases where delta(x) is 0, which produce (-)infinity, we can change
      // the comparison to delta(y1) * delta(x2) == delta(y2) * delta(x1).

      // Get the base slope from the first 2 points, and use the first point to
      // calculate the slopes with the successive points.
      let base_point = &coordinates[0];
      let base_delta_x = base_point[0] - coordinates[1][0];
      let base_delta_y = base_point[1] - coordinates[1][1];
      for point in &coordinates[2..] {
          let delta_x = base_point[0] - point[0];
          let delta_y = base_point[1] - point[1];
          if base_delta_y * delta_x != delta_y * base_delta_x {
              return false;
          }
      }
      true
  }
}
