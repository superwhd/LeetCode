class  Solution(object):
    def  minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if  not  s:
            return  0
        isPalidrome =  [([- 1] *  len(s)) for  i in  xrange(len(s))]
        def  ckPalidrome(l, r):
            if  l >=  r:
                return  1
            if  isPalidrome[l][r] !=  - 1:
                return  isPalidrome[l][r]
            isPalidrome[l][r] =  0
            if  s[l] ==  s[r]:
                isPalidrome[l][r] =  ckPalidrome(l +  1, r -  1)
            return  isPalidrome[l][r]
        
        f =  [len(s)] *  (len(s) +  1)
        f[0] =  0
        for  i in  xrange(1, len(s) +  1):
            for  j in  xrange(1, i +  1):
                if  ckPalidrome(j -  1, i -  1):
                    f[i] =  min(f[i], f[j -  1] +  1)
        return  f[len(s)] -  1
