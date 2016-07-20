class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = [ch for ch in s.lower() if 'a' <= ch <= 'z' or '0' <= ch <= '9']
        return s == s[::-1]