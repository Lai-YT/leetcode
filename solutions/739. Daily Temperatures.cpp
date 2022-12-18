#include <cstddef>
#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    auto days_to_wait =
        std::vector<int>(temperatures.size() /* narrow to int */, 0);

    for (std::size_t curr_day = 0; curr_day < temperatures.size(); ++curr_day) {
      /* current day is the first warmer day to these previous days */
      while (HasDayInWait_() &&
             temperatures.at(curr_day) > temperatures.at(PrevDayInWait_())) {
        days_to_wait.at(PrevDayInWait_()) = curr_day - PrevDayInWait_();
        WarmerDayOfPrevIsFound_();
      }
      WaitForWarmerDay_(curr_day);
    }
    return days_to_wait;
  }

 private:
  /* a monotonic decreasing stack:
    the closer to the bottom, the higher the temperature is at that day */
  std::stack<int> mono_s_{};

  void WaitForWarmerDay_(const int day) { mono_s_.push(day); }

  bool HasDayInWait_() { return !mono_s_.empty(); }

  int PrevDayInWait_() const { return mono_s_.top(); }

  void WarmerDayOfPrevIsFound_() { mono_s_.pop(); }
};
