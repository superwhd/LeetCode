class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        lx, rx = max(A, E), min(C, G)
        ly, ry = max(B, F), min(D, H)
        return (C - A) * (D - B) + (G - E) * (H - F) - max(rx - lx, 0) * max(ry - ly, 0)
        
        
