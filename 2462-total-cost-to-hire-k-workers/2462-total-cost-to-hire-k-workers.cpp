class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ret = 0;
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int i = 0, j = n - 1, count = 0; 
        while(count < k){
            while(pq1.size() < candidates && i <=j) pq1.push(costs[i++]);
            while(pq2.size() < candidates && i <=j) pq2.push(costs[j--]);
            int a = pq1.empty()? INT_MAX:pq1.top();
            int b = pq2.empty()? INT_MAX:pq2.top();
            if(a <= b){
                ret += a;
                pq1.pop();
            }else{
                ret += b;
                pq2.pop();
            }
            ++count;
            
        }
        return ret;
    }
};