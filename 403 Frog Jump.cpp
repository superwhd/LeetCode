class Solution {
public:
    bool canCross(vector< int>&  stones) {
        set< pair< int, int>  >  f;
        set< long long>  has;
        queue< pair< int, int>  >  q;
        q.push(make_pair(stones[0], 0));
        for  (auto tmp : stones) {
            has.insert(tmp);
        }
        int t =  stones.back();
        while  (! q.empty()) {
            auto s =  q.front();
            q.pop();
            long long v;
            for  (v =  0ll +  s.second +  s.first -  1; v <=  s.second +  s.first +  1; v++ ) {
                if  (v >  s.first) {
                    int step =  v -  s.first;
                    if  (has.count(v) &&  ! f.count(make_pair((int)v, step))) {
                        if  (v ==  t)
                            return  true;
                        f.insert(make_pair(v, step));
                        q.push(make_pair(v, step));
                    }
                }
            }
        }
        return  false;
    }
};
