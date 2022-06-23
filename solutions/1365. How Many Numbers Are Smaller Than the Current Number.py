class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        """
        (1) Put numbers into buckets, where number equals to index. This is O(n).
        (2) Walk through the buckets and make them accumulative buckets.
        Value at index a means how many numbers are smaller than the current number.
        This is O(n).
        (3) Walk through the original list and lookup the buckets to see how many
        numbers are smaller than current, and place the result into another list.
        This is O(n).
        => O(n) overall.
        """
        buckets: List[int] = [0] * 101  # 0 <= nums[i] <= 100
        # (1)
        for num in nums:
            buckets[num] += 1
        # (2)
        accum: int = 0
        for i in range(0, 101):
            buckets[i], accum = accum, buckets[i] + accum
        # (3)
        results: List[int] = []
        for num in nums:
            results.append(buckets[num])
        
        return results
