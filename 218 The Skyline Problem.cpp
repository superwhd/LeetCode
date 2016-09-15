class Solution {
public:
    vector< pair< int, int>>  getSkyline(vector< vector< int>>&  buildings) {
        vector< vector< int>  >  marks;
        for  (auto & building : buildings) {
            marks.push_back(vector< int> {building[0], building[2], 1});
            marks.push_back(vector< int> {building[1], building[2], -1});
        }
        sort(marks.begin(), marks.end());
        int last =  0;
        int i, j;
        modify(0, 1);
        vector< pair< int, int>  >  ans;
        for  (i =  0; i <  marks.size(); i++ ) {
            for  (j =  i; j <  marks.size() &&  marks[i][0] ==  marks[j][0]; j++ ) {
                modify(marks[j][1], marks[j][2]);
            }
            int now =  heights.rbegin()-> first;
            if  (now !=  last) {
                ans.push_back(make_pair(marks[i][0], now));
                last =  now;
            }
            i =  j -  1;
        }
        return  ans;
    }
private:
    map< int, int>  heights;
    void modify(int x, int y) {
        heights[x] +=  y;
        if  (! heights[x])
            heights.erase(x);
    }
};
