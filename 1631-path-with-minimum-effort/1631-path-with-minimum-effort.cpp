class Solution {
public:
    struct comp{
        bool operator()(tuple<int,int,int>&a, tuple<int,int,int>&b){
            return get<2>(a) > get<2>(b);
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        distances[0][0] = 0;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, comp> pq;
        pq.push(make_tuple(0, 0, 0));
        vector<vector<int>> ds{{0, 1}, {1, 0}, {0, -1},{-1, 0}};
        while(!pq.empty()){
            tuple<int,int,int> cur = pq.top();
            pq.pop();
            int i = get<0>(cur);
            int j = get<1>(cur);
            int dis = get<2>(cur);
            if(i == m - 1 && j == n - 1) return dis;
            if(dis > distances[i][j]) continue;
            for(vector<int>& d : ds){
                int newi = i + d[0];
                int newj = j + d[1];
                if(newi <  0 || newi > m - 1 || newj < 0 || newj > n - 1) continue;
                int newdis = max(distances[i][j], abs(heights[i][j]- heights[newi][newj]));
                if(newdis < distances[newi][newj]){
                    distances[newi][newj] = newdis;
                    pq.push(make_tuple(newi, newj, newdis));
                }
            }
        }
        return 0;
    }
};