class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int rk = 0;
        if (ruleKey == "color") rk = 1;
        else if (ruleKey == "name") rk = 2;
        int count = 0;
        for (auto& strVec : items) {
            if (strVec.at(rk) == ruleValue) ++count;
        }
        return count;
    }
};
