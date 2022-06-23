class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> t(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            t.at(i) = (i % 2) + t.at(i >> 1);
        }
        return std::move(t);
    }
};
