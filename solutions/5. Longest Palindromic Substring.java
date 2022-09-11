class Solution {
  private String str;
  private int maxBegin = 0;
  private int maxEnd = 0;
  private boolean[][] isPalindrome;

  public String longestPalindrome(final String s) {
    InitMaxRangeIndexAndMemoTable(s);
    for (int i = 0; i < str.length(); ++i) {
      for (int j = i; j < str.length(); ++j) {
        if (isPalindrome(i, j) && (j - i + 1) > maxLen()) {
          maxBegin = i;
          maxEnd = j;
        }
      }
    }
    return str.substring(maxBegin, maxEnd + 1);
  }

  private void InitMaxRangeIndexAndMemoTable(final String str) {
    this.str = str;
    isPalindrome = new boolean[str.length()][str.length()];
    maxBegin = 0;
    maxEnd = 0;
  }

  /** <code>begin</code> and <code>end</code> are both included. */
  private boolean isPalindrome(final int begin, final int end) {
    if (isPalindrome[begin][end]) {
      return true;
    }
    if (isSingleLetter(begin, end)
        || areTwinLetters(begin, end)
        || areIdenticalLetters(begin, end) && isPalindrome(begin + 1, end - 1)) {
      isPalindrome[begin][end] = true;
      return true;
    }
    return false;
  }

  private boolean isSingleLetter(final int begin, final int end) {
    return begin == end;
  }

  private boolean areTwinLetters(final int begin, final int end) {
    return end == begin + 1 && areIdenticalLetters(begin, end);
  }

  private boolean areIdenticalLetters(final int begin, final int end) {
    return str.charAt(begin) == str.charAt(end);
  }

  private int maxLen() {
    return maxEnd - maxBegin + 1;
  }
}
