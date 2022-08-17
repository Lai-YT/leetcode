class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        for (const std::string& word : words) {
            std::string transformation = transformWord_(word);
            /* the method should be named `insertIfNotContain` */
            uniqueTransformations_.insert(transformation);
        }
        return uniqueTransformations_.size();
    }
​
private:
    std::unordered_set<std::string> uniqueTransformations_{};
    const std::array<std::string, 26> letterOrderToMorseCode_{
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
