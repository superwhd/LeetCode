class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        n = len(matrix)
        m = len(matrix[0])
        x = n - 1
        y = 0
        a = matrix
        while 0 <= x < n and 0 <= y < m:
            if a[x][y] == target:
                return True
            if target < a[x][y]:
                x -= 1
            else:
                y += 1
        return False
        
