class Solution {
public:
    int strStr(string haystack, string needle) {
        if  (needle ==  "")
            return  0;
        for  (int i =  0; i +  needle.size() <=  haystack.size(); i++ ) {
            int j;
            for  (j =  0; j <  needle.size(); j++ ) {
                if  (haystack[i +  j] !=  needle[j])
                    break ;
            }
            if  (j ==  needle.size())
                return  i;
        }
        return  -1;
    }
};
