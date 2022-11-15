class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int s1 = 0, s2 = 1, ret = 0;
        for(int i = 1; i < n; i++){
            ret = s1 + s2;
            s1 = s2;
            s2 = ret;
        }
        return ret;
        
    }
};