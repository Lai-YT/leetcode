class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int indegree[n + 1], outdegree[n + 1];
        for (int i = 0; i <= n; ++i) {
            indegree[i] = 0;
            outdegree[i] = 0;
        }
​
        for (auto t : trust) {
            indegree[t.at(1)] += 1;
            outdegree[t.at(0)] += 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == (n - 1) && outdegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
