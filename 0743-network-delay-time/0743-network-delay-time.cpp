class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ts(n, INT_MAX);
        ts[k - 1] = 0;
        vector<vector<tuple<int,int>>> graph(n);
        for(vector<int>& t : times){
            int from = t[0] - 1;
            int to = t[1] - 1;
            int cost = t[2];
            graph[from].push_back({cost, to});
        }
        
        priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> pq;
        pq.push({0, k - 1});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int cost = get<0>(cur);
            int to = get<1>(cur);
            if(cost > ts[to]) continue;
            for(auto & tp : graph[to]){
                int next = get<1>(tp);
                int nt = cost + get<0>(tp);
                if(nt < ts[next]){
                    ts[next] = nt;
                    pq.push({nt, next});
                }
            }
        }
        int res = *max_element(ts.begin(), ts.end());
        return res == INT_MAX? -1 : res;
        
    }
};