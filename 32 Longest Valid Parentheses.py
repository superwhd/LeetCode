class  Solution(object):
    def  longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        f =  [- 2] *  (len(s) +  1)
        f[0] =  - 1
        now =  0
        ans =  0
        for  i, ch in  enumerate(s):
            if  ch ==  '(':
                now +=  1
                if  f[now] ==  - 2:
                    f[now] =  i
            else :
                f[now] =  - 2
                now -=  1
                if  f[now] !=  - 2:
                    ans =  max(ans, i -  f[now])
                if  f[now] ==  - 2:
                    f[now] =  i
        return  ans
                
