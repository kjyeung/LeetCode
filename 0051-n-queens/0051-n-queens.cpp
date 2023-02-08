class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        bt(res, board, 0);
        return res;
    }
    
    void bt(vector<vector<string>>& res, vector<string>& board, int next){
        if(next == board.size()){
            res.push_back(board);
            return;
        }
        
        for(int i = 0; i < board[0].size();i++){
            board[next][i] = 'Q';
            if(valid(board, next, i)){
                bt(res,board, next + 1);
            }
            board[next][i] = '.';
        }
        return;
    }
    
    bool valid(vector<string>& board, int row, int col){
        for(int i = 0; i < row;i++){
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row - 1,j = col - 1; i >=0 &&j >=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row - 1,j = col + 1; i >=0 && j < board[0].size();i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};