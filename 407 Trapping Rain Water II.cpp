
class Solution {
public:
    int trapRainWater(vector< vector< int>>  & heightMap) {
        if  (! heightMap.size())
            return  0;
        a =  heightMap;
        n =  heightMap.size();
        m =  heightMap[0].size();
        int i, j;
        set< pair< int, int>  >  vis;
        for  (i =  0; i <  n; i++ ) {
            for  (j =  0; j <  m; j++ ) {
                if  (i ==  0 ||  j ==  0 ||  i ==  n -  1 ||  j ==  m -  1) {
                    heap.push(Node(i, j, heightMap[i][j]));
                    vis.insert(make_pair(i, j));
                }
            }
        }

        int dx[] =  {0, 1, 0, -1};
        int dy[] =  {1, 0, -1, 0};
        int ans =  0;

        while  (! heap.empty()) {
            Node s =  heap.top();
            heap.pop();
            for  (int i =  0; i <  4; i++ ) {
                Node v(s.x +  dx[i], s.y +  dy[i], s.h);
                if  (in(v.x, v.y) &&  ! vis.count(make_pair(v.x, v.y))) {
                    if  (v.h >  a[v.x][v.y])
                        ans +=  v.h -  a[v.x][v.y];
                    else  v.h =  a[v.x][v.y];
                    a[v.x][v.y] =  v.h;
                    vis.insert(make_pair(v.x, v.y));
                    heap.push(v);
                }
            }
        }
        return  ans;
    }

private:
    vector< vector< int>>  a;

    bool in(int x, int y) {
        return  0 <=  x &&  x <  n &&  0 <=  y &&  y <  m;
    }

    struct Node {
        Node() {}

        Node(int _x, int _y, int _h) {
            x =  _x;
            y =  _y;
            h =  _h;
        }

        int x, y, h;

        bool operator < (const Node & t) const {
            return  h >  t.h;
        }
    };

    priority_queue< Node>  heap;
    int n, m;

};
