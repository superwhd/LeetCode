class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        def getStr(range):
            if range[0] == range[1]:
                return str(range[0])
            return str(range[0]) + '->' + str(range[1])
            
        if [] == nums:
            return []
        range = None
        res = []
        for num in nums:
            if not range:
                range = [num, num]
            elif num > range[1] + 1:
                res.append(getStr(range))
                range = [num, num]
            else:
                range[1] = num
        if range:
            res.append(getStr(range))
        return res