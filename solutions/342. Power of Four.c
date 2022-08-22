bool hasOnlyOneNonzeroBit(const int n) {
    /* minus one causes the bits to flip, so & should result to 0 */
    return !(n & (n - 1));
}
​
/* power of 2 has bit at even */ 
bool hasNonzeroBitAtOdd(const int n) {
    return n & 0b1010101010101010101010101010101;
}
​
bool isPowerOfFour(int n){
    return n > 0 && hasOnlyOneNonzeroBit(n) && hasNonzeroBitAtOdd(n);
}
​
