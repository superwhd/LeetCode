class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        g = {}
        for fr, to in tickets:
            if not fr in g:
                g[fr] = []
            if not to in g:
                g[to] = []
            g[fr].append(to)
        for x in g:
            g[x] = sorted(g[x])
        
        ans = []
        
        def dfs(x):
            for i, y in enumerate(g[x]):
                if y != -1:
                    g[x][i] = -1
                    dfs(y)
            ans.append(x)
        dfs("JFK")
        return ans[::-1]
