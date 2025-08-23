#include <bits/stdc++.h>

class Solution {
public:
    int minimumSum(std::vector<std::vector<int>>& grid) {
        // The ends are all exclusive.
        auto minimumArea = [&](int uy, int ly, int lx, int rx) {
            auto rowHasOne = [&](int y, int begin, int end) {
                for (int x = begin; x < end; x++)
                    if (grid[y][x]) return true;
                return false;
            };
            auto colHasOne = [&](int x, int begin, int end) {
                for (int y = begin; y < end; y++)
                    if (grid[y][x]) return true;
                return false;
            };

            int uyy = uy;
            while (uyy < ly) {
                if (rowHasOne(uyy, lx, rx)) break;
                ++uyy;
            }
            // All zeros.
            if (uyy == ly) {
                return 0;
            }
            int lxx = lx;
            while (lxx < rx) {
                if (colHasOne(lxx, uyy, ly)) break;
                ++lxx;
            }
            int lyy = ly - 1;
            while (lyy > uyy) {
                if (rowHasOne(lyy, lxx, rx)) break;
                --lyy;
            }
            int rxx = rx - 1;
            while (rxx > lx) {
                if (colHasOne(rxx, uyy, lyy + 1)) break;
                --rxx;
            }

            return (lyy - uyy + 1) * (rxx - lxx + 1);
        };

        auto H = grid.size(), W = grid[0].size();
        auto min = std::numeric_limits<int>::max();

        /*
            -------------
            |    (a)    |
            |           |
            -------------
            | (b) | (c) |
            |     |     |
            -------------
        */
        for (auto y = 0ul; y < H; y++) {
            auto a = minimumArea(0, y + 1, 0, W);
            for (auto x = 0u; x < W; x++) {
                auto b = minimumArea(y + 1, H, 0, x + 1);
                auto c = minimumArea(y + 1, H, x + 1, W);
                min = std::min(min, a + b + c);
            }
        }
        /*
            -------------
            | (b) | (c) |
            |     |     |
            ------------
            |           |
            |    (a)    |
            -------------
        */
        for (auto y = H - 1; y != -1; y--) {
            auto a = minimumArea(y + 1, H, 0, W);
            for (auto x = 0ul; x < W; x++) {
                auto b = minimumArea(0, y + 1, 0, x + 1);
                auto c = minimumArea(0, y + 1, x + 1, W);
                min = std::min(min, a + b + c);
            }
        }
        /*
            -------------
            |     | (b) |
            |     |     |
            | (a) -------
            |     |     |
            |     | (c) |
            -------------
        */
        for (auto x = 0ul; x < W; x++) {
            auto a = minimumArea(0, H, 0, x + 1);
            for (auto y = 0u; y < H; y++) {
                auto b = minimumArea(0, y + 1, x + 1, W);
                auto c = minimumArea(y + 1, H, x + 1, W);
                min = std::min(min, a + b + c);
            }
        }
        /*
            -------------
            |     |     |
            | (b) |     |
            ------- (a) |
            |     |     |
            | (c) |     |
            -------------
        */
        for (auto x = W - 1; x != -1; x--) {
            auto a = minimumArea(0, H, x + 1, W);
            for (auto y = 0ul; y < H; y++) {
                auto b = minimumArea(0, y + 1, 0, x + 1);
                auto c = minimumArea(y + 1, H, 0, x + 1);
                min = std::min(min, a + b + c);
            }
        }
        /*
            -------------
            |    (a)    |
            ------------- <- y
            |    (b)    |
            ------------- <- yy
            |    (c)    |
            -------------
        */
        for (auto y = 0; y < H; y++) {
            for (auto yy = y + 1; yy < H; yy++) {
                auto a = minimumArea(0, y + 1, 0, W);
                auto b = minimumArea(y + 1, yy + 1, 0, W);
                auto c = minimumArea(yy + 1, H, 0, W);
                min = std::min(min, a + b + c);
            }
        }
        /*
           -------------
           |   |   |   |
           |   |   |   |
           |(a)|(b)|(c)|
           |   |   |   |
           |   |   |   |
           -------------
        */
        for (auto x = 0ul; x < W; x++) {
            for (auto xx = x + 1; xx < W; xx++) {
                auto a = minimumArea(0, H, 0, x + 1);
                auto b = minimumArea(0, H, x + 1, xx + 1);
                auto c = minimumArea(0, H, xx + 1, W);
                min = std::min(min, a + b + c);
            }
        }

        return min;
    }
};

int main() {
    auto solver = Solution{};
    std::vector<std::vector<int>> grid = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
    };
    std::cout << solver.minimumSum(grid) << "\n";
    return 0;
}
