class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        costs[0][0] = 0;
        vector<vector<int>> ds{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()){
            tuple<int,int,int>  cur = pq.top();
            pq.pop();
            int cost = get<0>(cur);
            int i = get<1>(cur);
            int j = get<2>(cur);
            if(i == m - 1 && j == n - 1) return cost;
            if(cost > costs[i][j]) continue;
            for(vector<int> & d : ds){
                int ii = i + d[0];
                int jj = j + d[1];
                if(ii < 0 || ii > m - 1 || jj < 0 || jj > n - 1) continue;
                int newcost = max(cost, abs(heights[ii][jj] - heights[i][j]));
                if(newcost < costs[ii][jj]){
                    costs[ii][jj] = newcost;
                    pq.push({newcost, ii ,jj });
                }
            }
        }
        return costs[m - 1][n - 1];
        
    }
};