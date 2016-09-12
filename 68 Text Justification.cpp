class Solution {
public:
    vector< string>  fullJustify(vector< string>&  words, int maxWidth) {
        int n =  words.size();
        vector< int>  f(words.size() +  1), lst(words.size() +  1);
        fill(f.begin(), f.end(), 0x3f3f3f);
        f[0] =  0;
        for  (int i =  1; i <=  n; i++ ) {
            int sum =  0;
            for  (int j =  i; j >=  1; j-- ) {
                sum +=  words[j -  1].size();
                if  (j <  i) {
                    sum++ ;
                }
                if  (sum >  maxWidth)
                    break ;
                if  (f[i] >  f[j -  1] +  1) {
                    f[i] =  f[j -  1] +  1;
                    lst[i] =  j -  1;
                }
            }
            // cout << i << ", " << f[i] << ", " << lst[i] << endl;
        }
        vector< string>  ans;
        for  (int i =  n; i; i =  lst[i]) {
            // cout << i << endl;
            string tmp;
            int j, l =  lst[i] +  1, r =  i;
            int len =  0;
            for  (j =  l; j <=  r; j++ ) {
                len +=  words[j -  1].size();
            }
            if  (i ==  n) {
                for  (int j =  l; j <=  r; j++ ) {
                    if  (j >  l)
                        tmp +=  " ";
                    tmp +=  words[j -  1];
                }
                while  (tmp.size() <  maxWidth)
                    tmp +=  " ";
            } else  if  (l ==  r) {
                tmp =  words[l -  1];
                while  (len <  maxWidth) {
                    tmp +=  " ";
                    len++ ;
                }
            } else  {
                int totalSpace =  maxWidth -  len;
                int average =  totalSpace / (r -  l);
                tmp =  words[l -  1];
                for  (j =  l +  1; j <=  r; j++ ) {
                    int spaceLen =  average;
                    if  (average *  (r -  j +  1) <  totalSpace)
                        spaceLen++ ;
                    totalSpace -=  spaceLen;
                    for  (int k =  0; k <  spaceLen; k++ ) {
                        tmp +=  " ";
                    }
                    tmp +=  words[j -  1];
                }
            }
            ans.push_back(tmp);
        }
        reverse(ans.begin(), ans.end());
        return  ans;
    }
};
