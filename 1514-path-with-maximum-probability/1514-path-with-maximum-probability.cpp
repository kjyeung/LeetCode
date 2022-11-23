class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<tuple<double, int>, vector<tuple<double, int>>, less<tuple<double, int>>> pq;
        
        vector<vector<tuple<double, int>>> graph(n);
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
            double p = get<0>(cur);
            int to = get<1>(cur);
            if(to == end) return p;
            if(p < dis[to]) continue;
            for(auto e : graph[to]){
                int next = get<1>(e);
                double newp = p * get<0>(e);
                if(newp > dis[next]){
                    dis[next] = newp;
                    pq.push({newp, next});
                }
            }
        }
        return dis[end]; 
        
        
    }
};