class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        def isClosure(str, i):
            return i + 1 < len(str) and str[i + 1] == '*'
        
        def charMatch(ch1, ch2):
            return ch2 == '.' or ch1 == ch2
                    
        def match(s, i, p, j):
            if i == len(s) and j == len(p):
                return True
            if j == len(p):
                return False
            if isClosure(p, j):
                newI = i - 1
                while newI < len(s):
                    newI += 1
                    if match(s, newI, p, j + 2):
                        return True
                    if newI < len(s) and not charMatch(s[newI], p[j]):
                        break
                return False
            else:
                if i == len(s):
                    return False
                return charMatch(s[i], p[j]) and match(s, i + 1, p, j + 1)
        
        lastClosure = None
        newP = ''
        i = 0
        while i < len(p):
            if isClosure(p, i):
                if lastClosure != p[i]:
                    newP += p[i] + '*'
                    lastClosure = p[i]
                i += 2
            else:
                lastClosure = None
                newP += p[i]
                i += 1
        p = newP
        return match(s, 0, p, 0)