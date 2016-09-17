class  Solution(object):
    def  subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        cnt =  collections.Counter(nums)
        a =  cnt.items()
        ans =  []
        def  dfs(dep, now):
            if  dep ==  len(a):
                ans.append(now[:])
                return  
            for  i in  xrange(a[dep][1] +  1):
                dfs(dep +  1, now)
                now.append(a[dep][0])
            for  i in  xrange(a[dep][1] +  1):
                now.pop()
        dfs(0, [])
        return  ans
