class  Solution(object):
    def  largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        fa =  range(0, len(heights))
        l =  range(0, len(heights))
        r =  range(0, len(heights))
        def  gf(x):
            if  fa[x] ==  x:
                return  x
            fa[x] =  gf(fa[x])
            l[fa[x]] =  min(l[fa[x]], l[x])
            r[fa[x]] =  max(r[fa[x]], r[x])
            return  fa[x]
        
        lst =  [(height, i) for  i, height in  enumerate(heights)]
        lst =  reversed(sorted(lst))
        ans =  0
        inserted =  [False] *  len(heights)
        for  height, index in  lst:
            inserted[index] =  True
            if  index and  inserted[index -  1]:
                fa[gf(index)] =  fa[gf(index -  1)]
            if  index +  1 <  len(heights) and  inserted[index +  1]:
                fa[gf(index)] =  fa[gf(index +  1)]
            ans =  max(ans, height *  (r[gf(index)] -  l[gf(index)] +  1))
        return  ans
