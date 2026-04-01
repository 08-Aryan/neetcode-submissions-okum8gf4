class Solution {
public:
    void dfs(vector<string> &board,vector<vector<string>> &res,int r){
        if(r==board.size()){
            res.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(isSafe(r,i,board)){
                board[r][i]= 'Q';
                dfs(board,res,r+1);
                board[r][i]='.';
            }
        }
        return;
    }
    bool isSafe(int r,int c,vector<string> board){
        // check till befor col as we are moving in a row from left to right if there 
        for(int j=0;j<r;j++){
            if(board[j][c]=='Q'){
                return false;
            }
        }
        for(int i=r-1,j=c-1;i>=0 && j >= 0 ; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=r-1,j=c+1;i>=0 && j < board.size() ; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<string> board( n, string(n,'.'));
      vector<vector<string>> res;
      dfs(board,res,0);
      return res;  
    }
};
