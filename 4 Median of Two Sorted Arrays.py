class  Solution(object):
    def  findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def  median(nums):
            if  len(nums) %  2:
                return  nums[len(nums) /  2]
            return  sum(nums[len(nums) /  2 -  1 : len(nums) /  2 +  1]) *  0.5
        
        if  not  nums1 and  not  nums2:
            return  0
        if  not  nums1 or  not  nums2:
            nums =  nums1 if  nums1 else  nums2
            return  median(nums)
        
        def  rank(x, nums):
            s =  0
            e =  len(nums) -  1
            while  (s <=  e):
                mid =  (s +  e) >>  1
                if  nums[mid] <=  x:
                    s =  mid +  1
                else :
                    e =  mid -  1
            return  s
            
        def  find(k, nums1, nums2):
            
            def  solve(k, a, b):
                s =  0
                e =  len(a) -  1
                while  s <=  e:
                    mid =  (s +  e) >>  1
                    cnt =  mid +  rank(a[mid], b)
                    if  cnt >=  k:
                        e =  mid -  1
                    else :
                        s =  mid +  1

                if  (s >=  len(a)):
                    return  (0, False)
                flag1 =  (s +  rank(a[s], b)) >=  k
                ans =  s
                s =  0
                e =  len(b) -  1
                while  s <=  e:
                    mid =  (s +  e) >>  1
                    if  a[ans] >  b[mid]:
                        s =  mid +  1
                    else :
                        e =  mid -  1
                flag2 =  (s +  ans) <=  k

                return  (a[ans], flag1 and  flag2)
            
            res =  solve(k, nums1, nums2)
            if  res[1]:
                return  res[0]
            res =  solve(k, nums2, nums1)
            if  res[1]:
                return  res[0]
            return  2222222222
        
        len_sum =  len(nums1) +  len(nums2)
        if  len_sum %  2:
            return  find(len_sum /  2, nums1, nums2)
        else :
            return  0.5 *  (find(len_sum /  2 -  1, nums1, nums2) +  find(len_sum /  2, nums1, nums2))


