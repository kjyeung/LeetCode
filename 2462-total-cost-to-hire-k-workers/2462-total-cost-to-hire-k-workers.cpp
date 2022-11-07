class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ret = 0;
        int n = costs.size();
        priority_queue<tuple<int,int>, vector<tuple<int,int>>,greater<tuple<int,int>>> pq;
        int left = min(candidates - 1, n / 2 - 1);
        int right = max(n / 2, n - candidates);
        
        for(int i = 0; i <=left;i++){
            pq.push(make_tuple(costs[i], 1));
        }
        for(int i = n - 1; i >= right;i-- ){
            pq.push(make_tuple(costs[i], 2));
        }
        
        for(int i = 0; i < k;i++){
            auto cur = pq.top();
            pq.pop();
            long long cost = get<0>(cur);
            ret += cost;
            int place = get<1>(cur);
            if(left < right - 1 ){
                if(place == 1){
                    ++left;
                    pq.push(make_tuple(costs[left], place));
                }else{
                    --right;
                    pq.push(make_tuple(costs[right], place));
                }
            }
            
        }
        
        return ret;
    }
};