class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        if not board:
            return 0
        ans = 0
        n, m = len(board), len(board[0])
        a = board
        for i in xrange(n):
            for j in xrange(m):
                if a[i][j] == 'X' and (not i or a[i - 1][j] == '.') and (not j or a[i][j - 1] == '.'):
                    ans += 1
        return ans
