class  Solution(object):
    def  getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        f =  [[- 1] *  (n +  2) for  i in  xrange(n +  2)]
        def  dfs(l, r):
            if  l >=  r:
                return  0
            if  f[l][r] !=  - 1:
                return  f[l][r]
            mid1 =  (l +  r) >>  1
            f[l][r] =  1 <<  30
            for  mid in  xrange(l, r +  1):
                f[l][r] =  min(f[l][r], mid +  max(dfs(mid +  1, r), dfs(l, mid -  1)))
            return  f[l][r]
        return  dfs(1, n)
