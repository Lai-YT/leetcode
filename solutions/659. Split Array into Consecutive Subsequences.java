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
​
    private int countDuplicateOfIndex(final int beginIndex) {
        int duplicateCount = 0;
        for (int i = beginIndex, curr = nums[i];
                i < nums.length && curr == nums[i];
                ++i) {
            ++duplicateCount;
        }
        return duplicateCount;
    }
​
    private void assignCountsOnCurrToPrev() {
        pc.lenOne = cc.lenOne;
        pc.lenTwo = cc.lenTwo;
        pc.lenEqualToOrGreaterThanThree = cc.lenEqualToOrGreaterThanThree;
    }
​
    private boolean hasLenLowerThanThreeEndsWithPrev() {
        return pc.lenOne != 0 || pc.lenTwo != 0;
    }
​
    private boolean hasEnoughDuplicateToExtendShortSubsequences() {
        return duplicateCountOfCurr >= pc.lenOne + pc.lenTwo;
    }
​
    private void extendLenEqualToOrGreaterThanThree() {
        cc.lenEqualToOrGreaterThanThree = pc.lenTwo + Math.min(
                pc.lenEqualToOrGreaterThanThree,
                duplicateCountOfCurr - pc.lenTwo - pc.lenOne);
    }
​
    private void extendLenOneIfEnoughRemainingDuplicates() {
        int remainingDuplicates = duplicateCountOfCurr - pc.lenOne - pc.lenTwo - pc.lenEqualToOrGreaterThanThree;
        cc.lenOne = remainingDuplicates > 0 ? remainingDuplicates : 0;
    }
}
​
