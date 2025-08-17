#include <bits/stdc++.h>

class Solution {
    enum {
        WATER = 0,
        LAND = 1,
    };

    struct Cell {
        int x, y;
    };

public:
    int maxDistance(std::vector<std::vector<int>>& grid) {
        const auto n = grid.size();

        // To find the water cell that is farthest from any land,
        // we use multi-source BFS, with the lands being the sources.
        // The last water cell visited is the answer.
        auto queue = std::queue<Cell>{};
        auto visited = std::vector(n, std::vector(n, false));

        // Helper functions.
        auto isWater = [&](const Cell& c) { return grid[c.y][c.x] == WATER; };
        auto isLand = [&](const Cell& c) { return grid[c.y][c.x] == LAND; };
        auto markAsVisited = [&](const Cell& c) { visited[c.y][c.x] = true; };
        auto isInGrid = [&](const Cell& c) {
            return 0 <= c.x && c.x < n && 0 <= c.y && c.y < n;
        };
        auto isVisited = [&](const Cell& c) { return visited[c.y][c.x]; };
        auto addAllUnVisitedNeighboringWaters = [&](const Cell& c) {
            Cell offsets[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (auto&& off : offsets) {
                auto neighbor = Cell{c.x + off.x, c.y + off.y};
                if (!isInGrid(neighbor) || isVisited(neighbor)) {
                    continue;
                }
                markAsVisited(neighbor);
                queue.push(std::move(neighbor));
            }
        };

        // 1. Push the waters to the queue.
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                auto c = Cell{x, y};
                if (isLand(c)) {
                    // Notice that all lands are marked as visited. We can then
                    // only check whether the cell is visited afterward.
                    markAsVisited(c);
                    queue.push(std::move(c));
                }
            }
        }
        // 2. Start BFS.
        auto distance = -1;
        while (!queue.empty()) {
            ++distance;
            auto numWaterAtThisDistance = queue.size();
            for (auto i = 0ul; i < numWaterAtThisDistance; i++) {
                auto c = queue.front();
                queue.pop();
                addAllUnVisitedNeighboringWaters(c);
            }
        }

        return distance == 0 ? -1 : distance;
    }
};
