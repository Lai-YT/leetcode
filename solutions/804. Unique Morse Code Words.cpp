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
        ".--",
        "-..-",
        "-.--",
        "--..",
    };
​
    std::string transformWord_(const std::string& word) const {
        std::string transformation{};
        for (const char letter : word) {
            const int letterOrder = getLowerCaseLetterOrder_(letter);
            transformation += letterOrderToMorseCode_.at(letterOrder);
        }
        return transformation;
    }
​
    /* a is 0, z is 25, ... */
    int getLowerCaseLetterOrder_(const char lowerCaseLetter) const {
        return lowerCaseLetter - 97;
    }
​
};
​
