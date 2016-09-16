class  Solution(object):
    def  combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        ans =  []
        def  dfs(lst, dep):
            if  not  (k -  dep):
                ans.append(lst[:])
            start =  lst[dep -  1] +  1 if  dep else  1
            for  i in  xrange(start, n +  1):
                lst.append(i)
                dfs(lst, dep +  1)
                lst.pop()
        dfs([], 0)
        return  ans
