class  Solution(object):
    def  spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        ds =  zip([0, 1, 0, - 1], [1, 0, - 1, 0])
        d =  0
        pos =  [0, 0]
        ans =  []
        if  not  matrix:
            return  ans
        a =  matrix
        def  out(x, y):
            return  x <  0 or  x >=  len(a) or  y <  0 or  y >=  len(a[0])
        for  i in  xrange(len(matrix) *  len(matrix[0])):
            ans.append(a[pos[0]][pos[1]])
            a[pos[0]][pos[1]] =  - 212121
            new_pos =  [(pos[i] +  ds[d][i]) for  i in  xrange(2)]
            if  out(new_pos[0], new_pos[1]) or  a[new_pos[0]][new_pos[1]] ==  - 212121:
                d +=  1
                d %=  4
                new_pos =  [(pos[i] +  ds[d][i]) for  i in  xrange(2)]
            pos =  new_pos
        return  ans
print  Solution().spiralOrder([[ 1, 2, 3 ],[ 4, 5, 6 ],[ 7, 8, 9 ]])
