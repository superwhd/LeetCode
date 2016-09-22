class Solution {
public:
    string removeKdigits(string num, int k) {
        vector< char>  s(num.size());
        int top =  0, n =  num.size();        
        for  (int i =  0; i <  n; i++ ) {
            while  (top &&  num[i] <  s[top] &&  k) {
                k-- ;
                top-- ;
            }
            s[++ top] =  num[i];
        }
        top -=  k;
        if  (! top)
            return  "0";
        string ans;
        int i =  1;
        for  (i =  1; i <=  top; i++ )
            if  (s[i] !=  '0')
                break ;
        for  (; i <=  top; i++ )
            ans.push_back(s[i]);
        if  (! ans.size())
            ans =  "0";
        return  ans;
            
    }
};
