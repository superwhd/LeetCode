class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        Counter = collections.Counter
        return Counter(s) == Counter(t)
