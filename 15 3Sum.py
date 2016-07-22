class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        a = sorted(nums)
        ans = set()
        for j in xrange(len(a)):
            i = 0
            k = len(a) - 1
            while i < j:
                while j < k and a[i] + a[j] + a[k] > 0:
                    k -= 1
                if i < j < k and a[i] + a[j] + a[k] == 0:
                    ans.add((a[i], a[j], a[k]))
                i += 1
        return list(ans)