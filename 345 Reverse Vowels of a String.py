class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = "aeiouAEIOU"
        info = [(s[i], i) for i in xrange(len(s)) if s[i] in vowels]
        if not info:
            return s
        ch, pos = zip(*info)
        print ch, pos
        info = zip(ch[::-1], pos)
        res = list(s)
        for ch, pos in info:
            res[pos] = ch
        return ''.join(res)
