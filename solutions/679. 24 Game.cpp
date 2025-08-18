#include <bits/stdc++.h>

class Solution {
public:
    bool judgePoint24(std::vector<int>& cards) {
        // Try all combinations. "c" denote card and "o" denote operator.
        //      c o c o c o c
        // Each card can only be picked once.
        char ops[] = {'+', '-', '*', '/'};
        std::ranges::sort(cards);
        do {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        // Try all five different nestings.
                        // (a) 0 1 2 3
                        auto a =
                            operate(operate(operate(cards[0], cards[1], ops[i]),
                                            cards[2], ops[j]),
                                    cards[3], ops[k]);
                        // (b) 0 1 (2 3)
                        auto b = operate(operate(cards[0], cards[1], ops[i]),
                                         operate(cards[2], cards[3], ops[k]),
                                         ops[j]);
                        // (c) 0 (1 2) 3
                        auto c =
                            operate(operate(cards[0],
                                            operate(cards[1], cards[2], ops[j]),
                                            ops[i]),
                                    cards[3], ops[k]);
                        // (d) 0 (1 2 3)
                        auto d =
                            operate(cards[0],
                                    operate(operate(cards[1], cards[2], ops[j]),
                                            cards[3], ops[k]),
                                    ops[i]);
                        // (e) 0 (1 (2 3))
                        auto e =
                            operate(cards[0],
                                    operate(cards[1],
                                            operate(cards[2], cards[3], ops[k]),
                                            ops[j]),
                                    ops[i]);

                        for (auto&& res : {a, b, c, d, e}) {
                            if (std::abs(res - 24.0) < 1e-6) {
                                return true;
                            }
                        }
                    }
                }
            }
        } while (std::ranges::next_permutation(cards).found);

        return false;
    }

private:
    double operate(double a, double b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        assert(false);
    }
};
