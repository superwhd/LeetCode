class  Solution(object):
    def  simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        arr =  path.split('/')
        arr =  filter(lambda  x : x !=  '.' and  x !=  '', arr)
        res =  []
        for  string in  arr:
            if  string ==  '..':
                if  res:
                    res.pop()
            else :
                res.append(string)
        ans =  ''
        for  string in  res:
            ans +=  '/'
            ans +=  string
        if  ans ==  '':
            ans +=  '/'
        return  ans
