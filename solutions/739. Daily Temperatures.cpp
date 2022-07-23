class Solution {
public:
  std::vector<int> dailyTemperatures(vector<int>& temperatures) {
    auto answer = std::vector<int>(temperatures.size() /* narrow to int */, 0);
​
    /* a monotonic decreasing stack */
    auto s = std::stack<int>{};
    for (size_t curr_day = 0; curr_day < temperatures.size(); ++curr_day) {
      int curr_temp = temperatures.at(curr_day);
​
      /* current day is the first warmer day to these previous days */
      while (!s.empty() && curr_temp > temperatures.at(s.top())) {
        int prev_day = s.top();
        answer.at(prev_day) = curr_day - prev_day;
        s.pop();
      }
​
      /* current day look for warmer days in the future */
      s.push(curr_day);
    }
    return answer;
  }
};
​
