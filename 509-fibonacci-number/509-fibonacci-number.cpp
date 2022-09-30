class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int s1 = 0, s2 = 1, sum;
        for(int i = 1; i<n;i++){
            sum = s1 + s2;
            s1 = s2;
            s2 = sum;
        }
        return sum;
    }
};