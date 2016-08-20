class  Solution(object):
    def  generateMatrix(self, n):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if  not  n:
            return  []
        ds =  zip([0, 1, 0, - 1], [1, 0, - 1, 0])
        d =  0
        pos =  [0, 0]
        a =  [([- 212121] *  n) for  i in  xrange(n)]
        def  out(x, y):
            return  x <  0 or  x >=  len(a) or  y <  0 or  y >=  len(a[0])
        for  i in  xrange(n *  n):
            a[pos[0]][pos[1]] =  i +  1
            new_pos =  [(pos[i] +  ds[d][i]) for  i in  xrange(2)]
            if  out(new_pos[0], new_pos[1]) or  a[new_pos[0]][new_pos[1]] !=  - 212121:
                d +=  1
                d %=  4
                new_pos =  [(pos[i] +  ds[d][i]) for  i in  xrange(2)]
            pos =  new_pos
        return  a
print  Solution().generateMatrix(3)
