# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class  Solution(object):
    def  deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        pos =  [0]
        def  peek():
            return  s[pos[0]]
        
        def  next():
            pos[0] +=  1
            
        def  isEnd():
            return  pos[0] ==  len(s)
            
        def  parse():
            if  isEnd():
                return  NestedInteger()
            token =  peek()
            if  token ==  '[':
                res =  NestedInteger()
                firstTime =  True
                next()
                while  not  isEnd() and  peek() !=  ']':
                    if  not  firstTime:
                        # read ','
                        next()
                    firstTime =  False
                    part =  parse()
                    res.add(part)
                if  not  isEnd():
                    next()
            else :
                sgn =  1
                if  token ==  '-':
                    sgn =  - sgn
                    next()
                num =  0
                while  (not  isEnd()) and  (ord(peek()) in  xrange(ord('0'), ord('9') +  1)):
                    token =  peek()
                    num *=  10
                    num +=  ord(token) -  ord('0')
                    next()
                res =  NestedInteger(num *  sgn)
            return  res
        
        return  parse()
                
