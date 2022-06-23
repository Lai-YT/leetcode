class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        def visit(r: int, c: int) -> None:
            grid[r][c] = '#'  
            
        def is_land(r: int, c: int) -> bool:
            """
            This also implies it can't be visited,
            since the visited land is marked with '#', not '1' any more.
            """
            return grid[r][c] == '1'
        
        def in_grid(r: int, c: int) -> bool:
            return 0 <= r < rows and 0 <= c < cols
​
        def dfs(r: int, c: int) -> None:
            stack: List[Tuple[int]] = [(r, c)]
            
            while stack:
                row, col = stack.pop()
                directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
                
                for dr, dc in directions:
                    r, c = row + dr, col + dc
                    if in_grid(r, c) and is_land(r, c):
                        stack.append((r, c))
                        visit(r, c)
            # end dfs    
        
        rows, cols = len(grid), len(grid[0])
        islands: int = 0
                
        for r in range(rows):
            for c in range(cols):
                if is_land(r, c):
                    visit(r, c)
                    dfs(r, c)
                    islands += 1
        return islands
