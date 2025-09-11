#include <bits/stdc++.h>

#include <string>

class Solution {
public:
    std::string sortVowels(std::string s) {
        // Use counting sort.
        char vs[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        auto isVowel = [](char c) {
            switch (c) {
                case 'A':
                    return 0;
                case 'E':
                    return 1;
                case 'I':
                    return 2;
                case 'O':
                    return 3;
                case 'U':
                    return 4;
                case 'a':
                    return 5;
                case 'e':
                    return 6;
                case 'i':
                    return 7;
                case 'o':
                    return 8;
                case 'u':
                    return 9;
            }
            return -1;
        };
        int counts[sizeof(vs) / sizeof(vs[0])] = {0};
        for (char c : s) {
            if (auto pos = isVowel(c); pos != -1) {
                ++counts[pos];
            }
        }
        int v_pos = 0;
        for (char &c : s) {
            if (auto pos = isVowel(c); pos != -1) {
                while (counts[v_pos] == 0) {
                    ++v_pos;
                }
                c = vs[v_pos];
                --counts[v_pos];
            }
        }
        return s;
    }
};
