class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter = collections.Counter(s)
        lst = counter.items()
        mx = 0
        ans = 0
        flag = 0
        for x, y in lst:
            if y & 1:
                ans += y - 1
                flag = 1
            else:
                ans += y
        return ans + flag
                
