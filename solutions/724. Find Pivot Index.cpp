class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /* One may use `std::accumulate` to calculate the sum concisely
            but that puts extra overhead. */
        int sum = 0;
        for (const int num : nums) { sum += num; }
        /* Since we're looking for the left-most pivot,
            a window slides from the left to the right,
            dynamically checking the sum of both sides. */
        int rightSum = sum;
        int leftSum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (leftSum == rightSum - nums.at(i)) {
                return i;
            }
            rightSum -= nums.at(i);
            leftSum += nums.at(i);
        }
        return -1;
    }
};
