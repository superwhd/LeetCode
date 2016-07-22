class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        nums.append(0)
        n = len(nums)
        for i in xrange(n):
            res ^= i
            res ^= nums[i]
        return res