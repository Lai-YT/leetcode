int numberOfSteps(int num) {
  return num ? sizeof(int) * 8 - __builtin_clz(num) - 1 +
                   __builtin_popcount(num)
             : 0;
}
