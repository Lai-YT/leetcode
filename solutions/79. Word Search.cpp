#include <bits/stdc++.h>

class Solution {
    struct Cell {
        int x, y;
    };

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        const auto m = board.size();
        const auto n = board[0].size();

        // We run DFS from all cells which have their letter be word[0].
        //
        // To optimize for speed, count the letter frequencies. If the letter in
        // board is not enough for the word, we can return early.
        // (700 ms -> 100 ms)
        //
        // Also, if the frequency of the last letter is less than the first
        // letter, reverse the word. This reduces the amount of DFS performed.
        // (100 ms -> 0 ms)

        auto freqOnBoard = std::vector<int>(128, 0);
        for (auto y = 0l; y < m; y++) {
            for (auto x = 0l; x < n; x++) {
                ++freqOnBoard[board[y][x]];
            }
        }
        auto freqInWord = std::vector<int>(128, 0);
        for (auto l : word) {
            ++freqInWord[l];
        }
        for (int i = 0; i < 128; i++) {
            if (freqOnBoard[i] < freqInWord[i]) {
                return false;
            }
        }

        if (freqOnBoard[word.back()] < freqOnBoard[word.front()]) {
            std::ranges::reverse(word);
        }

        auto starts = std::vector<Cell>{};
        for (auto y = 0l; y < m; y++) {
            for (auto x = 0l; x < n; x++) {
                if (board[y][x] == word[0]) {
                    starts.emplace_back(x, y);
                }
            }
        }

        auto isOnBoard = [&](const Cell& c) {
            return 0 <= c.x && c.x < n && 0 <= c.y && c.y < m;
        };
        auto isLetter = [&](const Cell& c, char letter) {
            return board[c.y][c.x] == letter;
        };

        // NOTE: Using a set to record matches is too slow.
        auto markAsMatched = [&](const Cell& c) {
            board[c.y][c.x] -= ('z' - 'A' + 1);
        };
        auto restoreAsUnmatched = [&](const Cell& c) {
            board[c.y][c.x] += ('z' - 'A' + 1);
        };

        std::function<bool(const Cell&, std::size_t)> dfs =
            [&](const Cell& c, std::size_t pos) {
                if (pos == word.size()) {
                    return true;
                }

                if (!isOnBoard(c) || !isLetter(c, word[pos])) {
                    return false;
                }

                markAsMatched(c);

                Cell offsets[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for (auto&& off : offsets) {
                    auto neighbor = Cell{c.x + off.x, c.y + off.y};
                    if (dfs(neighbor, pos + 1)) {
                        return true;
                    }
                }

                restoreAsUnmatched(c);
                return false;
            };

        for (auto&& s : starts) {
            if (dfs(s, 0)) {
                return true;
            }
        }
        return false;
    }
};
