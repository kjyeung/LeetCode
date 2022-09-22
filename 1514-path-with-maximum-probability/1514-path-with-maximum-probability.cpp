class Solution {
public:
    struct comp{
        bool operator()(pair<int, double>& a, pair<int, double>& b){
            return a.second < b.second;
        }       
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probs(n, 0);
        probs[start] = 1.0;
        vector<vector<pair<int,double>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            int from = edges[i][0];
            int to = edges[i][1];
            double p = succProb[i];
            graph[from].push_back(make_pair(to, p));
            graph[to].push_back(make_pair(from, p));
        }
        
        priority_queue<pair<int, double>, vector<pair<int, double>>, comp> pq;
        pq.push(make_pair(start, 1.0));
        while(!pq.empty()){
            pair<int, double> cur = pq.top();
            pq.pop();
            int to = cur.first;
            double p = cur.second;
            if(to == end) return p;
            if(p < probs[to]) continue;
            for(pair<int, double> m : graph[to]){
                int next = m.first;
                double nextp = probs[to]*m.second;
                if(nextp > probs[next]){
                    probs[next] = nextp;
                    pq.push(make_pair(next, nextp));
                }
            }
        }
        return 0;
    }
};