class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    heights_ = std::move(height);
    left_ = 0;
    right_ = heights_.size() - 1;
    return MaxArea_();
  }

 private:
  using Index = int;

  std::vector<int> heights_;
  Index left_;
  Index right_;

  int MaxArea_() {
    int max = 0;
    while (!Crossed_()) {
      max = std::max(max, CalculateWater_());
      /* OPTIMIZATION: less calculation on water.
        If you don't find level higher than this,
        you're not gonna obtain more water,
        because the width is getting smaller. */
      const int water_level = WaterLevel_();
      while (!Crossed_() && heights_.at(left_) <= water_level) {
        ++left_;
      }
      while (!Crossed_() && heights_.at(right_) <= water_level) {
        --right_;
      }
    }
    return max;
  }

  bool Crossed_() const { return Width_() < 0; }

  int CalculateWater_() const { return WaterLevel_() * Width_(); }

  int Width_() const { return right_ - left_; }

  int WaterLevel_() const {
    return std::min(heights_.at(left_), heights_.at(right_));
  }
};
