class Solution {
    private static final int BASE_10 = 10;
    private Set<Integer> powerOfTwos;
    private List<Integer> digits;

    public boolean reorderedPowerOf2(int n) {
        setUpTableOfPowerOfTwo();
        decomposeNumberToDigits(n);
        return hasPowerOfTwoInPermutations(digits, digits.size());
    }

    private void setUpTableOfPowerOfTwo() {
        powerOfTwos = new HashSet<>();
        for (int n = 1; n <= 1_000_000_000; n *= 2) {
            powerOfTwos.add(n);
        }
    }

    private void decomposeNumberToDigits(int n) {
        digits = new ArrayList<>();
        while (n != 0) {
            digits.add(n % BASE_10);
            n /= BASE_10;
        }
    }

    private boolean hasPowerOfTwoInPermutations(final List<Integer> array, final int k) {
        if (k == 1) {
            return isNotZeroLeadingDigits() && isPowerOfTwo(composeDigitsToNumber());
        }
        for (int i = 0; i < k; i++) {
            if (hasPowerOfTwoInPermutations(array, k - 1)) {
                return true;
            }
            if (i < k - 1) {
                if (isEven(k)) {
                    swapDigits(i, k - 1);
                } else {
                    swapDigits(0, k - 1);
                }
            }
        }
        return false;
    }

    private boolean isNotZeroLeadingDigits() {
        return digits.get(digits.size() - 1) != 0;
    }

    private int composeDigitsToNumber() {
        int base = 1;
        int num = 0;
        for (final int d : digits) {
            num += d * base;
            base *= BASE_10;
        }
        return num;
    }

    private boolean isPowerOfTwo(final int n) {
        return powerOfTwos.contains(n);
    }

    private boolean isEven(final int n) {
        return n % 2 == 0;
    }

    private void swapDigits(final int i, final int j) {
        int temp = digits.get(i);
        digits.set(i, digits.get(j));
        digits.set(j, temp);
    }
}
