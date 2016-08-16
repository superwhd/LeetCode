class  Solution(object):
    def  generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans =  []
        def  dfs(dep, rest, string):
            if  not  dep and  not  rest:
                ans.append(string)
                return  
            if  rest:
                dfs(dep +  1, rest -  1, string +  '(')
            if  dep:
                dfs(dep -  1, rest, string +  ')')
        
        dfs(0, n, '')
        return  ans
