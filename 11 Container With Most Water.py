class  Solution(object):
    def  maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        pairs =  [(h, i) for  i, h in  enumerate(height)]
        pairs =  reversed(sorted(pairs))
        min_x =  len(height)
        max_x =  0
        ans =  0
        for  y, x in  pairs:
            ans =  max(ans, y *  max(x -  min_x, max_x -  x))
            min_x =  min(min_x, x)
            max_x =  max(max_x, x)
        return  ans
