class Solution {
public:
    void scan(const vector< int>  & height, bool reversed) {
        stack< int>  st;
        for  (size_t i =  0; i <  height.size(); i++ ) {
            while  (! st.empty() &&  (height[i] >=  height[st.top()])) {
                st.pop();
            }
            st.push(i);
        }
        while  (! st.empty()) {
            size_t index =  st.top();
            st.pop();
            if  (reversed)
                index =  remain.size() -  1 -  index;
            remain[index] =  true;
        }
    }
    int trap(vector< int>&  height) {
        remain.resize(height.size());
        scan(height, false);
        vector< int>  reversed_height =  height;
        reverse(reversed_height.begin(), reversed_height.end());
        scan(reversed_height, true);
        vector< pair< int, int>>  a;
        int ans =  0;
        for  (size_t i =  0; i <  height.size(); i++ ) {
            if  (remain[i])
                a.push_back(make_pair(i, height[i]));
            else  
                ans -=  height[i];
        }
        for  (size_t i =  1; i <  a.size(); i++ ) {
            ans +=  min(a[i].second, a[i -  1].second) *  (a[i].first -  a[i -  1].first -  1);
        }
        return  ans;
    }
private:
    vector< bool>  remain;
};
