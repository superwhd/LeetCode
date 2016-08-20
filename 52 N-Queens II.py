class  Solution(object):
    def  totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans =  [0]
        def  dfs(dep, col_state, diag1_state, diag2_state):
            if  dep ==  n:
                ans[0] =  ans[0] +  1
                return  
            for  i in  xrange(0, n):
                if  (not  (col_state >>  i &  1)) and  (not  (diag1_state >>  (i +  dep) &  1)) and  not  ((diag2_state >>  (n +  dep -  i) 
                    &  1)):
                    dfs(dep +  1, col_state |  (1 <<  i), diag1_state |  (1 <<  (i +  dep)), diag2_state |  (1 <<  (n +  dep -  i)))
        dfs(0, 0, 0, 0)
        return  ans[0]
                    

