class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int d1 = 0;
        int d2 = 1;
        int ret = 0;
        for(int i = 1; i < n; i++){
            ret = d1 + d2;
            d1 = d2;
            d2 = ret;
        }
        return ret;
    }
};