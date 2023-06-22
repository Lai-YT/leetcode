impl Solution {
  pub fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {
      let mut free_yesterday = 0;
      let mut hold_yesterday = -prices[0]; // to hold stock at day 0, buy at day 0;
      for i in 1..prices.len() {
          // 1. if we hold a stock, we can sale at day i, which then switches to free
          let free_today = free_yesterday.max(hold_yesterday + prices[i] - fee);
          // 2. if we not yet hold a stock, we can buy at day i, which then switches to hold
          let hold_today = hold_yesterday.max(free_yesterday - prices[i]);

          free_yesterday = free_today;
          hold_yesterday = hold_today;
      }
      // Selling the stock at the last day always give better profit then holding it.
      free_yesterday
  }
}
