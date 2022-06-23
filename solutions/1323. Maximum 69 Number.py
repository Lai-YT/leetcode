class Solution:
    def maximum69Number (self, num: int) -> int:
        split_num: List[int] = []
        while num != 0:
            split_num.append(num % 10)
            num //= 10
        for i in reversed(range(len(split_num))):
            if split_num[i] == 6:
                split_num[i] = 9
                break
        answer: int = 0
        for i, n in enumerate(split_num):
            answer += n * (10 ** i)
        return answer
