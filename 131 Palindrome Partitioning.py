class  Solution(object):
    def  partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        n =  len(s) +  1
        last =  [[] for  i in  xrange(len(s) +  1)]
        last[0] =  [0]
        def  isPalindrome(l, r):
            return  s[l:r] ==  s[l:r][::- 1]
            
        for  i in  xrange(n):
            if  last[i]:
                for  j in  xrange(i +  1, n):
                    l =  i
                    r =  j
                    if  isPalindrome(l, r):
                        last[j].append(i)
        
        ans =  []
        def  dfs(i, now):
            if  not  i:
                ans.append(now[::- 1])
                return 
            for  lastpos in  last[i]:
                now.append(s[lastpos:i])
                dfs(lastpos, now)
                now.pop()
        dfs(n -  1, [])
        return  ans
