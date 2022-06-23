class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums.at(i);
            if (m.count(complement) != 0) return vector<int> {i, m[complement]};
            else m[nums.at(i)] = i;
        }
        return vector<int>();
    }
};
