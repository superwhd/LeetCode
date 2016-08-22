class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res;
        res.resize(max(a.size(), b.size()) +  1);
        for  (int i =  0; i <  a.size() ||  i <  b.size(); i++ ) {
            if  (i <  a.size())
                res[i] +=  a[i] -  '0';
            if  (i <  b.size())
                res[i] +=  b[i] -  '0';
            if  (res[i] >=  2) {
                res[i +  1] +=  1;
                res[i] -=  2;
            }
        }
        if  (! res.back())
            res =  res.substr(0, res.size() -  1);
        reverse(res.begin(), res.end());
        for  (int i =  0; i <  res.size(); i++ )
            res[i] +=  '0';
        return  res;
    }
};
