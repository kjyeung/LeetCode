class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<tuple<double, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            graph[a].push_back(make_tuple(p, b));
            graph[b].push_back(make_tuple(p, a));
        }
        
        vector<double> ps(n, 0);
        ps[start] = 1.0;
        priority_queue<tuple<double, int>> pq;
        pq.push(make_tuple(1.0, start));
        
        while(!pq.empty()){
            tuple<double, int> cur = pq.top();
            pq.pop();
            double p = get<0>(cur);
            int to = get<1>(cur);
            if(p < ps[to]) continue;
            if(to == end) return p;
            for(tuple<double, int> t : graph[to]){
                double np = get<0>(t) * p;
                int next = get<1>(t);
                if(np > ps[next]){
                    ps[next] = np;
                    pq.push(make_tuple(np,next));
                }
            }
        }
        return 0;
    }
};