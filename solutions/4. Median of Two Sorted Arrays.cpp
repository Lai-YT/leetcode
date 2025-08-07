#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Draw a mid-line through both num1 and num2, where all numbers at the left
    // are not greater than those at the right. Then by comparing the numbers
    // next to the line, we can get the median.
    // If the number of numbers is odd, the median is at the left of the line.
    // Since the number of numbers and the left side of the line is
    // deterministic: (m + n + 1) / 2, we perform binary search on one of the
    // sequence, the line position of the other sequence can than be

    // NOTE: Use signed integer since we allow falling to negative.
    const int m = nums1.size();
    const int n = nums2.size();

    const int nleft = (m + n + 1) / 2; // This handles both odd and even cases
                                       // because the floor is taken.
    auto at_with_bound_guard = [](vector<int> &nums, int i) {
      if (i < 0) {
        return numeric_limits<int>::min();
      }
      if (i >= nums.size()) {
        return numeric_limits<int>::max();
      }
      return nums[i];
    };
    auto l = 0, r = m;
#define pos1 (l + (r - l) / 2)
#define pos2 (nleft - pos1)
    while (l < r) {
      if (at_with_bound_guard(nums1, pos1 - 1) >
          at_with_bound_guard(nums2, pos2)) {
        r = pos1 - 1;
      } else if (at_with_bound_guard(nums1, pos1) <
                 at_with_bound_guard(nums2, pos2 - 1)) {
        l = pos1 + 1;
      } else {
        break;
      }
    }
    if ((m + n) & 1) {
      return std::max(at_with_bound_guard(nums1, pos1 - 1),
                      at_with_bound_guard(nums2, pos2 - 1));
    }
    return (std::max(at_with_bound_guard(nums1, pos1 - 1),
                     at_with_bound_guard(nums2, pos2 - 1)) +
            std::min(at_with_bound_guard(nums1, pos1),
                     at_with_bound_guard(nums2, pos2))) /
           2.0;
  }
};
