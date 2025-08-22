from typing import List


class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        H, W = len(grid), len(grid[0])

        def row_has_one(y: int, begin: int = 0, end: int = W) -> bool:
            return any(grid[y][x] == 1 for x in range(begin, end))

        def col_has_one(x: int, begin: int = 0, end: int = H) -> bool:
            return any(grid[y][x] == 1 for y in range(begin, end))

        # We first find the upper y.
        uy = 0
        while uy < H:
            if row_has_one(uy):
                break
            uy += 1
        # Then the left x.
        # Since we already have the upper y, elements above don't have to be re-checked.
        lx = 0
        while lx < W:
            if col_has_one(lx, uy):
                break
            lx += 1
        # With the upper y and left x, we can view the grid as a smaller one.
        # The lower y can be found is the same fashion.
        ly = H - 1
        while ly > uy:
            if row_has_one(ly, lx):
                break
            ly -= 1
        # Finally, the right x.
        rx = W - 1
        while rx > lx:
            if col_has_one(rx, uy, ly + 1):
                break
            rx -= 1

        return (ly - uy + 1) * (rx - lx + 1)
