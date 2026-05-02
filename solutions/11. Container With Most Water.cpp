class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int m = 0;
        while (s < e) {
            m = std::max(m, std::min(height[s], height[e]) * (e - s));
            if (height[s] < height[e]) {
                ++s;
            } else {
                --e;
            }
        }
        return m;
    }
};
