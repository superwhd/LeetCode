class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        if not num:
            return False
        n = len(num)
        f = [[False] * n for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(i + 1, n):
                num1 = int(num[0:i + 1])
                num2 = int(num[i + 1:j + 1])
                if (num[0] == '0' and i) or (num[i + 1] == '0' and j > i + 1):
                    continue
                num3 = str(num1 + num2)
                k = len(num3)
                if j + k < n and num[j + 1: j + k + 1] == num3:
                    f[j + 1][j + k] = True
                    
        for i in xrange(n):
            for j in xrange(i, n):
                for k in xrange(j + 1, n):
                    if f[j + 1][k]:
                        num1 = int(num[i:j + 1])
                        num2 = int(num[j + 1:k + 1]) 
                        if (num[i] == '0' and j > i) or (num[j + 1] == '0' and k > j + 1):
                            continue
                        num3 = str(num1 + num2)
                        l = len(num3)
                        if k + l < n and num[k + 1:k + l + 1] == num3:
                            f[k + 1][k + l] = True
        for i in xrange(n):
            if f[i][n - 1]:
                return True
        return False
                        
                
