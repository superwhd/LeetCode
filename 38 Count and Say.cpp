class Solution {
public:
    string countAndSay(int n) {
        if  (n ==  1)
            return  "1";
        string str =  countAndSay(n -  1);
        string res =  "";
        for  (int i =  0; i <  str.size(); i++ ) {
            int j;
            for  (j =  i; j <  str.size() &&  str[i] ==  str[j]; j++ );
            res +=  std::to_string(j -  i);
            res +=  str[i];
            i =  j -  1;
        }
        return  res;
    }
};
