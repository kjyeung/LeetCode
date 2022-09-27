class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        costs[0][0] = 0;
        
        // -c, i, j
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> ds{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        pq.push(make_tuple(0, 0, 0));
        
        while(!pq.empty()){
            tuple<int,int,int> cur = pq.top();
            pq.pop();
            int c = get<0>(cur);
            int i = get<1>(cur);
            int j = get<2>(cur);
            if(c > costs[i][j]) continue;
            if(i == m - 1 && j == n - 1) return c;
            for(vector<int>& d : ds){
                int newi = i + d[0];
                int newj = j + d[1];
                if(newi < 0 || newi > m - 1 || newj <0 || newj > n - 1) continue;
                int newc = max(c, abs(heights[i][j] - heights[newi][newj]));
                if(newc < costs[newi][newj]){
                    costs[newi][newj] = newc;
                    pq.push(make_tuple(newc, newi, newj));
                }
            }
        }
        return costs[m - 1][n - 1];
    }
};