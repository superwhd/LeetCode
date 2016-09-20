class  Solution(object):
    def  calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        n =  len(dungeon)
        m =  len(dungeon[0])
        a =  dungeon
        f =  [[99999999] *  m for  i in  xrange(n)]
        f[n -  1][m -  1] =  max(1, 1 -  (a[n -  1][m -  1]))
        for  i in  xrange(n -  1, - 1, - 1):
            for  j in  xrange(m -  1, - 1, - 1):
                w =  a[i][j]
                if  i +  1 <  n:
                    f[i][j] =  min(f[i][j], f[i +  1][j] -  w)
                if  j +  1 <  m:
                    f[i][j] =  min(f[i][j], f[i][j +  1] -  w)
                f[i][j] =  max(f[i][j], 1)
        return  f[0][0]
