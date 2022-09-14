class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 0;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while(num < n * n){
            if(top <= bottom){
                for(int i = left; i<= right; i++){
                    res[top][i] = ++num;
                }
                ++top;
            }
            
            if(left <= right){
                for(int i = top; i <= bottom; i++){
                    res[i][right] = ++num;
                }
                --right;
            }
            
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    res[bottom][i] = ++num;
                }
                --bottom;
            }
            
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    res[i][left] = ++num;
                }
                ++left;
            }
        }
        return res;
    }
};