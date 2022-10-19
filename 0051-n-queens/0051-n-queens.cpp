class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> bd(n, string(n, '.'));
        bt(res, bd, 0);
        return res;
    }
    
    void bt(vector<vector<string>> & res, vector<string>& bd, int row){
        if(row == bd.size()){
            res.push_back(bd);
            return;
        }
        for(int i = 0; i < bd.size(); i++){
            if(!valid(bd, row, i)) continue;
            bd[row][i] = 'Q';
            bt(res, bd, row + 1);
            bd[row][i] = '.';
        }
        return;
    }
    
    bool valid(vector<string>& bd, int row, int col){
        for(int i = 0; i < row;i++){
            if(bd[i][col] == 'Q') return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j>=0;i--,j--){
            if(bd[i][j] == 'Q') return false;
        }
        
        for(int i = row - 1, j = col + 1; i >=0 && j < bd.size(); i--, j++){
            if(bd[i][j] == 'Q') return false;
        }
        return true;
    }
};