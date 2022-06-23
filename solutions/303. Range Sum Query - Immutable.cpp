class NumArray {
public:
    NumArray(std::vector<int>& nums) 
        :sums_(nums.size()) {
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += nums.at(i);
            sums_.at(i) = sum;
        }
    }
    
    int sumRange(int left, int right) {
        if (!left) {
            return sums_.at(right);
        }
        return sums_.at(right) - sums_.at(left - 1);
    }
    
private:
    // sums_ stores the sum of nums from 0 to themselves (include)    
    std::vector<int> sums_;
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
