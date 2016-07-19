class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def digitToStr(digit):
            if digit == '2':
                return 'abc'
            if digit == '3':
                return 'def'
            if digit == '4':
                return 'ghi'
            if digit == '5':
                return 'jkl'
            if digit == '6':
                return 'mno'
            if digit == '7':
                return 'pqrs'
            if digit == '8':
                return 'tuv'
            if digit == '9':
                return 'wxyz'
        if not digits:
            return []
        ans = ['']
        for digit in digits:
            ans = [(str + ch) for str in ans for ch in digitToStr(digit)]
        return ans