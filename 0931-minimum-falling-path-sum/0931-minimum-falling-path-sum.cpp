class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return matrix[0][0];
        int table[n][n]; memset(table, 20000, sizeof(table));
        for(int i = 0; i < n;i++){
            table[0][i] = matrix[0][i];
        }
        int res = INT_MAX;
        vector<int> ds{ -1, 0, 1};
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int d : ds){
                    if(j + d < 0 || j + d > n - 1) continue;
                    table[i][j] = min(table[i][j], table[i - 1][j + d]);
                }
                table[i][j] += matrix[i][j];
                if(i == n - 1){
                    res = min(res, table[i][j]);
                }
            }
        }
        return res;
    }
};