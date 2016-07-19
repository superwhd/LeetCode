class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        ans = []
        def dfs(dep, col_state, diag1_state, diag2_state, res):
            if dep == n:
                ans.append(res)
                return 
            for i in xrange(0, n):
                if (not (col_state >> i & 1)) and (not (diag1_state >> (i + dep) & 1)) and not ((diag2_state >> (n + dep - i) & 1)):
                    new_res = res[:]
                    new_res.append('.' * i + 'Q' + '.' * (n - i - 1))
                    dfs(dep + 1, col_state | (1 << i), diag1_state | (1 << (i + dep)), diag2_state | (1 << (n + dep - i)), new_res)
        dfs(0, 0, 0, 0, [])
        return ans
                    