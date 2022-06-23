class Solution {
    int count(vector<int>& ns, int target) {
        int cot = 0;
        for (int n : ns) {
            if (n == target) {
                ++cot;
            }
        }
        return cot;
    }
    
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_set<int> pool;
        int good_pairs = 0;
        for (int n : nums) {
            if (pool.find(n) == pool.end()) {
                int appear = count(nums, n);
                good_pairs += appear * (appear-1) / 2;
                pool.insert(n);
            }
        }
        return good_pairs;
    }
};
