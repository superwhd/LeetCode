class Solution {
public:
    int maxEnvelopes(vector< pair< int, int>>&  envelopes) {
        int n =  envelopes.size();
        vector< int>  f(n, 1);
        sort(envelopes.begin(), envelopes.end());
        if  (! n)
            return  0;
        for  (int i =  0; i <  n; i++ ) {
            for  (int j =  i +  1; j <  n; j++ ) {
                if  (envelopes[i].first <  envelopes[j].first &&  envelopes[i].second <  envelopes[j].second)
                    f[j] =  max(f[j], f[i] +  1);
            }
        }
        int ans =  0;
        for  (int i =  0; i <  n; i++ )
            ans =  max(ans, f[i]);
        return  ans;
    }
};
