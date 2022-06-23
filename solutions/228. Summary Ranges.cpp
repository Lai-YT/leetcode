class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result{};    
        if (nums.empty()) {
            return result;
        }
        int head = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums.at(i)-1 != nums.at(i-1)) {
                if (head != i-1) {
                    result.push_back(to_string(nums.at(head)) + "->" + to_string(nums.at(i-1)));
                } else {
                    result.push_back(to_string(nums.at(head)));
                }
                head = i;
            }
        }
        /* close the last possible range */
        if (head != nums.size()-1) {
            result.push_back(to_string(nums.at(head)) + "->" + to_string(nums.back()));
        } else {
            result.push_back(to_string(nums.at(head)));
        }
        return result;
    }
};
