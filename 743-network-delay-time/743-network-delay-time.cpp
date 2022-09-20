class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        
        for(vector<int>& t : times){
            graph[t[0] - 1].push_back(make_pair(t[1]-1, t[2]));
        }
        
        vector<int> ts(n, INT_MAX);
        ts[k - 1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        pq.push(make_pair(k - 1, 0));
        while(!pq.empty()){
            pair<int,int> cur = pq.top();
            pq.pop();
            int to = cur.first;
            int time = cur.second;
            if(time > ts[to]) continue;
            for(pair<int,int>& p : graph[to]){
                int next = p.first;
                int newtime = p.second + ts[to];
                if(newtime < ts[next]){
                    ts[next] = newtime;
                    pq.push(make_pair(next, newtime));
                }
            }
        }
        int res = *max_element(ts.begin(),ts.end());
        return res == INT_MAX? -1:res;
        
    }
};