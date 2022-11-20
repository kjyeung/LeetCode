class Solution {
public:
    int countTriples(int n) {
        //unordered_map<int,int> table;
        vector<int> table(n * n + 1);
        for(int i = 1; i <= n;i++){
            table[i * i] = true;
        }
        int res = 0;
        for(int i = 1; i <n; i++){
            for(int j = i + 1; i * i + j * j <= n * n; j++){
                res += table[i * i + j * j] * 2;
                
            }
        }
        return res;
    }
        
};