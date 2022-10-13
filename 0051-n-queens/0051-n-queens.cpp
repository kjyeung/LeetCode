class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n,string(n, '.'));
        backtrack(res, board, 0, n);
        return res;
    }
    
    void backtrack(vector<vector<string>> & res, vector<string>& board, int start, int end){
        if(start == end){
            res.push_back(board);
            return;
        }
        for(int i = 0; i < board.size();i++){
            if(check(board, start, i)){
                board[start][i] = 'Q';
                backtrack(res, board, start + 1, end);
                board[start][i] = '.';
            }
        }
        return;
    }
    
    bool check(vector<string> & board, int row, int col){
        for(int i = 0; i < row;i++){
            if(board[i][col] == 'Q') return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        
        for(int i = row - 1, j = col + 1; i >=0 && j < board.size(); i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};