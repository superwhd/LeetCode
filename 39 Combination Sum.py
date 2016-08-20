class  Solution(object):
    def  combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans =  []
        a =  candidates
        def  dfs(dep, plan, rest):
            if  dep ==  len(a):
                if  not  rest:
                    ans.append(plan)
                return  
            for  i in  xrange(rest /  a[dep] +  1):
                dfs(dep +  1, plan +  ([a[dep]] *  i), rest -  a[dep] *  i)
        dfs(0, [], target)
        return  ans
