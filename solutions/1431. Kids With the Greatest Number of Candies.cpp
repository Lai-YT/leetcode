class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> possibility(candies.size());
        int greatest = *(std::max_element(candies.begin(), candies.end())) - extraCandies;
        for (int i = 0; i < candies.size(); ++i) {
            possibility.at(i) = (candies.at(i) >= greatest);
        }
        return possibility;
    }
};
