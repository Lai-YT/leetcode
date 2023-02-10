class Solution:
    def minSteps(self, s: str, t: str) -> int:
        ALPHA_COUNT: int = 26

        diffs: list[int] = [0 for _ in range(ALPHA_COUNT)]
        for s_char, t_char in zip(s, t):
            diffs[ord(s_char) - ord('a')] += 1
            diffs[ord(t_char) - ord('a')] -= 1

        total_diff: int = 0
        for d in diffs:
            total_diff += abs(d)

        return total_diff // 2
