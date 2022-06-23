class Solution {
public:
  int hammingWeight(uint32_t n) {
    uint32_t mask = 1;
    size_t bits = 0;
    for (size_t i = 0; i < 32; ++i) {
      if (mask & n) {
        ++bits;
      }
      mask <<= 1;
    }
    return bits;
  }
};
