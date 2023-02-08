struct comp{
    bool operator()(const pair<double,int>&a, const pair<double, int>&b){
        return a.first < b.first;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probs(n, 0);
        probs[start] = 1;
        
        
        priority_queue<pair<double,int>, vector<pair<double,int>>,comp> pq; 
        vector<vector<pair<double,int>>> graph(n);
        for(int i = 0; i < edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];
            graph[a].push_back({p, b});
            graph[b].push_back({p, a});
        }
        pq.push({1.0, start});
        
        while(!pq.empty()){
            pair<double,int> cur = pq.top();
            pq.pop();
            int node = cur.second;
            double p = cur.first;
            if(p < probs[node]) continue;
            if(node == end) return p;
            for(pair<double,int>& np : graph[node]){
                double newp = p * np.first;
                int newnode = np.second;
                if(newp > probs[newnode]){
                    probs[newnode] = newp;
                    pq.push({newp, newnode});
                }
            }
        }
        return 0;
    }
};