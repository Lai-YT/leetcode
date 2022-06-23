class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> target(nums1.begin(), nums1.end());
        unordered_set<int> pool(nums2.begin(), nums2.end());
        vector<int> inter;
        for (int const t : pool) {
            if (target.find(t) != target.end()) {
                inter.push_back(t);
            }
        }
        return inter;
    }
};
