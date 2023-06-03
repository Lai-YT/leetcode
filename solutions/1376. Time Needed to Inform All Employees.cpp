class Solution {
 public:
  // Uses dynamic programming to get the informed time of all employees from
  // bottom up.
  int numOfMinutes(int n, int headID, std::vector<int>& manager,
                   std::vector<int>& informTime) {
    head_id_ = headID;
    manager_ = manager;
    inform_time_ = informTime;
    informed_time_ = std::vector<int>(n, NO_CACHE);
    informed_time_.at(headID) = 0;

    int max_time = 0;
    for (int employee = 0; employee < n; employee++) {
      max_time = std::max(GetInformedTime(employee), max_time);
    }
    return max_time;
  }

 private:
  int head_id_;
  std::vector<int> manager_;
  /// @brief The time a manager needs to inform the subordinates.
  std::vector<int> inform_time_;
  int NO_CACHE = -1;
  /// @brief Cached table. The time an employee is informed.
  std::vector<int> informed_time_;

  int GetInformedTime(int employee) {
    if (HasCachedInformedTime_(employee)) {
      return informed_time_.at(employee);
    }
    informed_time_.at(employee) = inform_time_.at(manager_.at(employee))
                                  + GetInformedTime(manager_.at(employee));
    return informed_time_.at(employee);
  }

  bool HasCachedInformedTime_(int employee) const {
    return informed_time_.at(employee) != NO_CACHE;
  }
};
