class  Solution(object):
    def  combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans =  []
        a =  candidates
        unique_a =  list(set(candidates))
        counts =  [sum([1 for  vv in  a if  vv ==  v]) for  v in  unique_a]
        a =  zip(unique_a, counts)
        def  dfs(dep, plan, rest):
            if  dep ==  len(a):
                if  not  rest:
                    ans.append(plan)
                return  
            v, cnt =  a[dep]
            for  i in  xrange(cnt +  1):
                if  rest >=  v *  i:
                    dfs(dep +  1, plan +  ([v] *  i), rest -  v *  i)

        dfs(0, [], target)
        return  ans

