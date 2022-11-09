class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ret = 1;
        while(!stk.empty() && stk.top().first <= price){
            ret += stk.top().second;
            stk.pop();
        }
        stk.push({price, ret});
        return ret;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */