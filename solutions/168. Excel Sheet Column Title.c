const int BUF_SIZE = 7 + 1;  /* (2 ^ 31 - 1) is at most 7 digit long, extra digit for \0 */
const int NUM_OF_ALPHABET = 26;
​
char toTitleDigit(const int n) {
    return 'A' + n;
}
​
char * convertToTitle(int columnNumber) {
    char * title = malloc(sizeof(char) * BUF_SIZE);
​
    /* the digits need to be filled backward */
    title[BUF_SIZE - 1] = '\0';
    int i = BUF_SIZE - 2;
    for (; columnNumber; --i) {
        /* works like a 64-BASE system after minus 1 */
        title[i] = toTitleDigit((columnNumber - 1) % NUM_OF_ALPHABET);
        columnNumber = (columnNumber - 1) / NUM_OF_ALPHABET;
    }
    /* adjusts to the "start" */
    return title + i + 1;
}
