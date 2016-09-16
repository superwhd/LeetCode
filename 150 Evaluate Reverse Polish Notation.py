class  Solution(object):
    def  evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        if  not  tokens:
            return  0
        stack =  []
        for  string in  tokens:
            if  string in  ('+', '-', '*', '/'):
                rhs =  stack[- 1]
                stack.pop()
                lhs =  stack[- 1]
                stack.pop()
                if  string ==  '+':
                    res =  lhs +  rhs
                elif  string ==  '-':
                    res =  lhs -  rhs
                elif  string ==  '*':
                    res =  lhs *  rhs
                else :
                    res =  int(math.trunc(float(lhs) /  rhs))
                print  res
                stack.append(res)
            else :
                stack.append(int(string))
        return  stack[0]
        
