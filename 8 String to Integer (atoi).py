class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if not str:
            return 0
        str = str.strip()
        mul = 1
        if str[0] in ('+', '-'):
            mul = -1 if (str[0] == '-') else 1
            str = str[1:]
        l = 0
        ans = 0
        while l < len(str):
            if '0' <= str[l] <= '9':
                ans *= 10
                ans += ord(str[l]) - ord('0')
            else:
                break
            l += 1
        ans *= mul
        maxint = (1 << 31) - 1
        ans = max(ans, -maxint -1)
        ans = min(ans, maxint)
        return ans