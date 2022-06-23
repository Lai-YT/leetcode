class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int times = 0;
        for (auto curr = points.begin(), next = points.begin() + 1;
             next != points.end();
             ++curr, ++next)
        {
            int x = curr->at(0) - next->at(0),
                y = curr->at(1) - next->at(1);
            times += max(abs(x), abs(y));
        }
        return times;
    }
};
