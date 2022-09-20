class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(vector<int>& e : times){
            int from = e[0] - 1;
            int to = e[1] - 1;
            int time = e[2];
            graph[from].push_back(make_pair(to, time));
        }
        vector<int> ts(n, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, comp> pq;
        ts[k - 1] = 0;
        pq.push(make_pair(k - 1, 0));
        while(!pq.empty()){
            pair<int,int> cur =pq.top();
            pq.pop();
            int to = cur.first;
            int time = cur.second;
            if(time > ts[to]) continue;
            for(pair<int,int> t:graph[to]){
                int next = t.first;
                int nt = ts[to] + t.second;
                if(nt < ts[next]){
                    ts[next] = nt;
                    pq.push(make_pair(next, nt));
                }
            }
        }
        int res = *max_element(ts.begin(), ts.end());
        return res == INT_MAX? -1:res;
    }
};