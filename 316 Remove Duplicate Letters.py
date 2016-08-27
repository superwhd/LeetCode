import  collections
class  Solution(object):
    def  removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        def  toInt(ch):
            return  ord(ch) -  ord('a')
        stack =  []
        cnt =  [0] *  26
        for  ch in  s:
            cnt[toInt(ch)] +=  1
        vis =  0
        for  i, ch in  enumerate(s):
            if  vis >>  toInt(ch) &  1:
                cnt[toInt(ch)] -=  1
                continue 
            while  stack and  stack[- 1] >  ch and  cnt[toInt(stack[- 1])]:
                vis ^=  1 <<  toInt(stack[- 1])
                stack.pop()
            stack.append(ch)
            vis |=  1 <<  toInt(ch)
            cnt[toInt(ch)] -=  1
        return  ''.join(stack)
            



