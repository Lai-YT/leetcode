class Solution {
public:
    static constexpr int BUCKET_SIZE = 6;  /* 'b', 'a', 'l', 'o', 'n', `all others` */
    int maxNumberOfBalloons(string text) {
        /* bucket count */ 
        int buckets[BUCKET_SIZE] = {0};
        for (const char chr : text) {
           ++buckets[charToIndex(chr)];
        }
​
        /* find min */
        int min = buckets[charToIndex('b')];
        buckets[charToIndex('l')] /= 2;
        buckets[charToIndex('o')] /= 2;
        for (int i = 1  /* 0 is `all others` */; i < BUCKET_SIZE; ++i) {
            if (buckets[i] < min) {
                min = buckets[i];
            }
        }
        return min;
    }
    
    int charToIndex(const char chr) const {
        switch (chr) {
            case 'b': return 1;
            case 'a': return 2;
            case 'l': return 3;
            case 'o': return 4;
            case 'n': return 5;
            default: return 0;
        } 
    }
};
