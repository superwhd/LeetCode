class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split('.')
        while v1 != [] and int(v1[-1]) == 0:
            v1 = v1[:-1]
        v2 = version2.split('.')
        while v2 != [] and int(v2[-1]) == 0:
            v2 = v2[:-1]
        def compare(l1, l2):
            if l1 == l2:
                return 0
            return 1 if l1 > l2 else -1
        for i in xrange(min(len(v1), len(v2))):
            num1 = int(v1[i])
            num2 = int(v2[i])
            t = compare(num1, num2)
            if t:
                return t
        return compare(len(v1), len(v2))