​
​
int singleNumber(int* nums, int numsSize){
    int check = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        check ^= nums[i];
    }
    return check;
}
