class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        //vector<vector<int>> table(m, vector<int>(n, INT_MAX));
        int table[m][n]; memset(table, 1000001, sizeof(table));
        table[0][0] = 0;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, 0, 0});
        vector<vector<int>> ds{{0, 1}, {1, 0},{0, -1}, {-1, 0}};
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int i = get<1>(cur);
            int j = get<2>(cur);
            int cost = get<0>(cur);
            
            if(cost > table[i][j]) continue;
            
            if(i == m - 1 && j == n - 1) return cost;
            
            for(auto &d : ds){
                int ii = i + d[0];
                int jj = j + d[1];
                if(ii < 0 || ii > m-1 || jj < 0 || jj > n - 1) continue;
                int newc = max(cost, abs(heights[i][j] - heights[ii][jj]));
                if(newc < table[ii][jj]) {
                    table[ii][jj] = newc;
                    pq.push({newc, ii, jj});
                }
                
            }
            
        }
        return table[m - 1][n - 1];
    }
};