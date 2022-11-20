class Solution {
public:
    int countTriples(int n) {
        if(n == 1) return 0;
        int res = 0;
        int max = n * n;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                for(int k = j + 1; k <= n; k++){
                    if(pow(i, 2) + pow(j, 2) == pow(k, 2)) res+=2;
                }
            }
        }
        return res;
        
    }
};