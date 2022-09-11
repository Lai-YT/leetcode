class Solution {
  private String str;

  public String longestPalindrome(final String s) {
    /*
     * Time complexity: the outer for-loop iterates n times,
     *  each expandAroundCenter may expand to the whole string, so is also n.
     *  We obtain O(n^2).
     * Space complexity: access with index, no memo, which is O(1).
     */

    str = s;
    int maxBegin = 0;
    int maxEnd = 0;  /* included */
    for (int i = 0; i < str.length(); ++i) {
      /* palindrome can be single or dual centered */
      final int len = Math.max(expandAroundCenter(i, i),
                               expandAroundCenter(i, i + 1));
      if (len > maxEnd - maxBegin + 1) {
        /*
         * Single centered palindrome has odd length, taking floor on (len - 1) / 2 and
         * len / 2 are the same;
         * dual centered palindrome has even length, since i is the left center, so
         * len has to be minus by 1 when calculating the begin.
         */
        maxBegin = i - (len - 1) / 2;
        maxEnd = i + len / 2;
      }
    }
    return str.substring(maxBegin, maxEnd + 1);
  }

  private int expandAroundCenter(int left, int right) {
    while (left >= 0 && right < str.length()
        && str.charAt(left) == str.charAt(right)) {
      --left;
      ++right;
    }
    return (right - 1) - (left + 1) + 1;  /* restore the last in/decreament */
  }
}
