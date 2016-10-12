class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not matrix:
            return []
        def bfs(a, starts):
            q = starts[:]
            head = 0
            n = len(a)
            m = len(a[0])
            vis = [[False] * m for i in xrange(n)]
            for start in starts:
                vis[start[0]][start[1]] = True
            ds = zip([0, 1, 0, -1], [1, 0, -1, 0])
            def isin(v):
                return 0 <= v[0] < n and 0 <= v[1] < m
            while head < len(q):
                s = q[head]
                head += 1
                for dx, dy in ds:
                    v = (s[0] + dx, s[1] + dy)
                    if isin(v) and not vis[v[0]][v[1]] and a[v[0]][v[1]] >= a[s[0]][s[1]]:
                        q.append(v)
                        vis[v[0]][v[1]] = True
            # print q
            # print ''
            return vis

        a = matrix
        n = len(a)
        m = len(a[0])

        starts1 = []
        starts2 = []
        for x in xrange(n):
            for y in xrange(m):
                if x == 0 or y == 0:
                    starts1.append((x, y))
                if (x == n - 1) or (y == m - 1):
                    starts2.append((x, y))

        vis1 = bfs(a, starts1)
        vis2 = bfs(a, starts2)
        res = []
        for x in xrange(n):
            for y in xrange(m):
                if vis1[x][y] and vis2[x][y]:
                    res.append((x, y))
        return res
