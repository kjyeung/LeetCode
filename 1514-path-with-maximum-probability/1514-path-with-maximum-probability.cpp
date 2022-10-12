class Solution {
public:
    struct comp{
        bool operator()(pair<int, double>& a, pair<int, double>& b){
            return a.second < b.second;
        }
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int ,double>> graph[n];
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            graph[a].push_back({b, p});
            graph[b].push_back({a, p});
        }
        
        vector<double> ps(n, 0);
        ps[start] = 1;
        priority_queue<pair<int, double>, vector<pair<int, double>>, comp> pq;
        pq.push({start, 1.0});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int to = cur.first;
            double p = cur.second;
            if(p < ps[to]) continue;
            if(to == end) return p;
            for(auto & t : graph[to]){
                int next = t.first;
                double newp = ps[to] * t.second;
                if(newp > ps[next]){
                    ps[next] = newp;
                    pq.push({next, newp});
                }
            }
            
        }
        return 0;
    }
};