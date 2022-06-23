class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string shuff(s.length(), '\0');
        for (int i = 0; i < s.length(); ++i) {
            shuff.at(indices.at(i)) = s.at(i);
        }
        return shuff;
    }
};
