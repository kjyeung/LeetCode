class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double, int>> pq;
        
        vector<vector<pair<double, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            graph[a].push_back({p, b});
            graph[b].push_back({p, a});
        }
        vector<double> dis(n, 0);
        dis[start] = 1.0;
        pq.push({1.0, start});
        
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            double p = cur.first;
            int to = cur.second;
            if(to == end) return p;
            if(p < dis[to]) continue;
            for(auto e : graph[to]){
                int next = e.second;
                double newp = p * e.first;
                if(newp > dis[next]){
                    dis[next] = newp;
                    pq.push({newp, next});
                }
            }
        }
        return dis[end]; 
        
        
    }
};