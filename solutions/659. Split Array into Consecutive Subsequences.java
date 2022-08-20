class Solution {
    private static int UNSET = -1001; /* smaller than any possible nums */
    private int[] nums;
    private CountsOfSequenceEndsWithPrev pc;
    private CountsOfSequenceEndsWithCurr cc;
    private int duplicateCountOfCurr = 0;

    private class CountsOfSequence {
        int lenOne = 0;
        int lenTwo = 0;
        int lenEqualToOrGreaterThanThree = 0;

        void resetCountsToZero() {
            lenOne = 0;
            lenTwo = 0;
            lenEqualToOrGreaterThanThree = 0;
        }
    }

    private class CountsOfSequenceEndsWithPrev extends CountsOfSequence {}

    private class CountsOfSequenceEndsWithCurr extends CountsOfSequence {}

    /**
     * Refer to
     * https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106495/Java-O(n)-time-and-O(1)-space-solution-greedily-extending-shorter-subsequence.
     * I like the way he or she tracks the possibility.
     */
    public boolean isPossible(int[] nums /* non-decreasing */) {
        this.nums = nums;
        pc = new CountsOfSequenceEndsWithPrev();
        cc = new CountsOfSequenceEndsWithCurr();
        for (int i = 0, prev = UNSET, curr = UNSET;
                i < nums.length;
                prev = curr, assignCountsOnCurrToPrev()) {
            curr = nums[i];
            duplicateCountOfCurr = countDuplicateOfIndex(i);
            i += duplicateCountOfCurr;
            if (curr != prev + 1) {
                if (hasLenLowerThanThreeEndsWithPrev()) {
                    return false;
                }
                cc.resetCountsToZero();
                cc.lenOne = duplicateCountOfCurr;
            } else {
                if (!hasEnoughDuplicateToExtendShortSubsequences()) {
                    return false;
                }
                cc.lenTwo = pc.lenOne;
                extendLenEqualToOrGreaterThanThree();
                extendLenOneIfEnoughRemainingDuplicates();
            }
        }
        return !hasLenLowerThanThreeEndsWithPrev();
    }

    private int countDuplicateOfIndex(final int beginIndex) {
        int duplicateCount = 0;
        for (int i = beginIndex, curr = nums[i];
                i < nums.length && curr == nums[i];
                ++i) {
            ++duplicateCount;
        }
        return duplicateCount;
    }

    private void assignCountsOnCurrToPrev() {
        pc.lenOne = cc.lenOne;
        pc.lenTwo = cc.lenTwo;
        pc.lenEqualToOrGreaterThanThree = cc.lenEqualToOrGreaterThanThree;
    }

    private boolean hasLenLowerThanThreeEndsWithPrev() {
        return pc.lenOne != 0 || pc.lenTwo != 0;
    }

    private boolean hasEnoughDuplicateToExtendShortSubsequences() {
        return duplicateCountOfCurr >= pc.lenOne + pc.lenTwo;
    }

    private void extendLenEqualToOrGreaterThanThree() {
        cc.lenEqualToOrGreaterThanThree = pc.lenTwo + Math.min(
                pc.lenEqualToOrGreaterThanThree,
                duplicateCountOfCurr - pc.lenTwo - pc.lenOne);
    }

    private void extendLenOneIfEnoughRemainingDuplicates() {
        int remainingDuplicates = duplicateCountOfCurr - pc.lenOne - pc.lenTwo - pc.lenEqualToOrGreaterThanThree;
        cc.lenOne = remainingDuplicates > 0 ? remainingDuplicates : 0;
    }
}
