class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not len(grid):
            return 0
        n = len(grid)
        m = len(grid[0])
        ans = 0
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        def dfs(grid, x, y):
            if x < 0 or x >= n or y < 0 or y >= m or grid[x][y] != '1':
                return
            grid[x][y] = '0'
            for dx, dy in dirs:
                dfs(grid, x + dx, y + dy)
        for x in xrange(n):
            for y in xrange(m):
                if grid[x][y] == '1':
                    ans += 1
                    dfs(grid, x, y)
        return ans