class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        dic = {}
        n = 0
        for eq in equations:
            for symbol in eq:
                if not symbol in dic:
                    dic[symbol] = n
                    n += 1
        f = [[-1.0] * n for i in xrange(n)]
        vis = [[False] * n for i in xrange(n)]
        iszero = [False] * n
        for eq, value in zip(equations, values):
            x, y = eq
            x, y = dic[x], dic[y]
            f[x][y] = value
            vis[x][y] = True
            if not value:
                iszero[x] = True
            else:
                f[y][x] = 1.0 / value
                vis[y][x] = True
        for k in xrange(n):
            for i in xrange(n):
                for j in xrange(n):
                    if not vis[i][j] and vis[i][k] and vis[k][j]:
                        f[i][j] = f[i][k] * f[k][j]
                        vis[i][j] = True
        res = []
        for q in queries:
            x, y = q
            if not x in dic or not y in dic:
                res.append(-1)
                continue
            x, y = dic[x], dic[y]
            if vis[x][y]:
                res.append(f[x][y])
            else:
                res.append(-1)
        return res
            
