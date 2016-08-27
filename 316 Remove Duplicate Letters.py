import  collections
class  Solution(object):
    def  removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        if  not  s:
            return  ''
        st =  [0] *  len(s)
        now =  0
        for  i in  xrange(len(s) -  1, - 1, - 1):
            ch =  s[i]
            now |=  1 <<  (ord(ch) -  ord('a'))
            st[i] =  now
        now =  0
        i =  0
        ans =  ''
        cou =  0
        all =  st[0]
        while  i <  len(s) and  now !=  all:
            j =  i
            minCh =  - 1 
            while  j <  len(s) and  (st[i] &  (all ^  now)) ==  (st[j] &  (all ^  now)):
                ch =  s[j]
                if  not  (now >>  (ord(ch) -  ord('a')) &  1) and  ((minCh ==  - 1) or  s[minCh] >  s[j]):
                    minCh =  j 
                j +=  1
            ans +=  s[minCh]
            now |=  1 <<  (ord(s[minCh]) -  ord('a'))
            i =  minCh +  1 
        return  ans


print  Solution().removeDuplicateLetters('abacb')
