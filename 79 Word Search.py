class  Solution(object):
    def  exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        step =  zip((0, 1, 0, - 1), (1, 0, - 1, 0))
        def  dfs(depth, x, y):
            if  not  (0 <=  x <  len(board) and  0 <=  y <  len(board[0])):
                return  False
            if  board[x][y] !=  word[depth] :
                return  False
            elif  depth +  1 ==  len(word):
                return  True
            board[x][y] =  '*'
            for  d in  step:
                if  dfs(depth +  1, x +  d[0], y +  d[1]):
                    return  True
            board[x][y] =  word[depth]
            return  False
        for  x in  xrange(len(board)):
            for  y in  xrange(len(board[0])):
                if  dfs(0, x, y):
                    return  True
        return  False
