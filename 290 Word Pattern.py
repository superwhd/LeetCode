class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        dic = {}
        dic2 = {}
        words = str.split(' ')
        if len(words) != len(pattern):
            return False
        for i, word in enumerate(words):
            if not word in dic:
                dic[word] = pattern[i]
                if pattern[i] in dic2:
                    return False
                dic2[pattern[i]] = word
            if pattern[i] != dic[word]:
                return False
        return True
