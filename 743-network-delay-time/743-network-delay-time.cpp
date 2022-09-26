class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(vector<int>& t: times){
            graph[t[0] - 1].push_back(make_pair(t[1] - 1, t[2]));
        }
        
        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(k - 1, 0));
        
        while(!pq.empty()){
            pair<int,int> cur= pq.top();
            pq.pop();
            int to = cur.first;
            int cost = cur.second;
            if(cost > dis[to]) continue;
            for(pair<int,int> p : graph[to]){
                int next = p.first;
                int cnext = p.second + cost;
                if(cnext < dis[next]){
                    dis[next] = cnext;
                    pq.push(make_pair(next, cnext));
                }
            }
        }
        int res = *max_element(dis.begin(), dis.end());
        return res == INT_MAX? -1: res;
    }
};