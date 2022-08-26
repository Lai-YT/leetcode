class Solution {
    static final List<Set<Character>> ROWS = Arrays.asList(
            new HashSet<Character>(Arrays.asList('q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p')),
            new HashSet<Character>(Arrays.asList('a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l')),
            new HashSet<Character>(Arrays.asList('z', 'x', 'c', 'v', 'b', 'n', 'm')));

    public String[] findWords(String[] words) {
        ArrayList<String> wordsOnOneRow = new ArrayList<>(words.length);
        for (final String word : words) {
            if (wordInRows(word.toLowerCase())) {
                wordsOnOneRow.add(word);
            }
        }
        return wordsOnOneRow.toArray(new String[wordsOnOneRow.size()]);
    }

    private boolean wordInRows(final String word) {
        for (final Set<Character> row : ROWS) {
            if (wordInRow(word, row)) {
                return true;
            }
        }
        return false;
    }

    private boolean wordInRow(final String word, final Set<Character> row) {
        for (int i = 0; i < word.length(); i++) {
            final char letter = word.charAt(i);
            if (!row.contains(letter)) {
                return false;
            }
        }
        return true;
    }
}
