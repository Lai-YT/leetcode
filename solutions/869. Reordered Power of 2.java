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
​
    private boolean isNotZeroLeadingDigits() {
        return digits.get(digits.size() - 1) != 0;
    }
​
    private int composeDigitsToNumber() {
        int base = 1;
        int num = 0;
        for (final int d : digits) {
            num += d * base;
            base *= BASE_10;
        }
        return num;
    }
​
    private boolean isPowerOfTwo(final int n) {
        return powerOfTwos.contains(n);
    }
​
    private boolean isEven(final int n) {
        return n % 2 == 0;
    }
​
    private void swapDigits(final int i, final int j) {
        int temp = digits.get(i);
        digits.set(i, digits.get(j));
        digits.set(j, temp);
    }
}
​
