# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class  Solution(object):
    def  insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        
        marks =  []
        for  interval in  intervals:
            marks.append((interval.start, 1))
            marks.append((interval.end, - 1))
        
        def  insertMark(mark):
            l =  0
            r =  len(marks) -  1
            while  l <=  r:
                mid =  l +  r >>  1
                if  mark <  marks[mid]:
                    r =  mid -  1
                else :
                    l =  mid +  1
            marks.insert(l, mark)
        insertMark((newInterval.start, 1))
        insertMark((newInterval.end, - 1))
        i =  0
        result =  []
        now =  0
        while  i <  len(marks):
            j =  i
            last =  now
            while  j <  len(marks) and  marks[j][0] ==  marks[i][0]:
                now +=  marks[j][1]
                j +=  1
            if  (not  not  now) ^  (not  not  last):
                result.append(marks[i][0])
            if  not  now and  not  last:
                result.append(marks[i][0])
                result.append(marks[i][0])
            i =  j
        result =  [(result[i -  1], result[i]) for  i in  xrange(1, len(result), 2)]
        return  result
