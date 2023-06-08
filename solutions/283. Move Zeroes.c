void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int* get_next_zero(int* nums, int numsSize, int* curr_pos);
int* get_next_non_zero(int* nums, int numsSize, int* curr_pos);

void moveZeroes(int* nums, int numsSize) {
  int* next_zero = get_next_zero(nums, numsSize, nums);
  int* next_non_zero = get_next_non_zero(nums, numsSize, next_zero);
  while (next_non_zero < nums + numsSize && next_zero < nums + numsSize) {
    swap(next_non_zero, next_zero);
    next_non_zero = get_next_non_zero(nums, numsSize, next_non_zero);
    next_zero = get_next_zero(nums, numsSize, next_zero);
  }
}

int* get_next_zero(int* nums, int numsSize, int* curr_pos) {
  while (curr_pos < nums + numsSize && *curr_pos != 0) {
    curr_pos++;
  }
  return curr_pos;
}

int* get_next_non_zero(int* nums, int numsSize, int* curr_pos) {
  while (curr_pos < nums + numsSize && *curr_pos == 0) {
    curr_pos++;
  }
  return curr_pos;
}
