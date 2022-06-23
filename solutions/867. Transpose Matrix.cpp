class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size(), col = A.at(0).size();
        vector<vector<int>> B(col, vector<int> (row, 0));
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                B.at(i).at(j) = A.at(j).at(i);
            }
        }
        return B;
    }
};
