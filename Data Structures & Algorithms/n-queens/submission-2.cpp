class Solution {
public:
    vector<bool> col;
    vector<bool> negdig;
    vector<bool> posdig;
    void dfs(vector<string> &board,vector<vector<string>> &res,int r){
        if(r==board.size()){
            res.push_back(board);
            return;
        }
        int n = board.size();
        for(int i=0;i<board.size();i++){
            if(isSafe(r,i,board)){
                board[r][i]= 'Q';
                col[i]=true;
                posdig[r+i]=true;
                negdig[r-i+n]=true;
                dfs(board,res,r+1);
                board[r][i]='.';
                col[i]=false;
                posdig[r+i]=false;
                negdig[r-i+n]=false;
            }
        }
        return;
    }
    bool isSafe(int r,int c,vector<string> board){
        // check till befor col as we are moving in a row from left to right if there 
        int n = board.size();
        if(col[c]){
            return false;
        }
        if(posdig[r+c]){
            return false;
        }
        if(negdig[r-c+n]){
            return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<string> board( n, string(n,'.'));
      col.resize(n,false);
      negdig.resize(2*n,false);
      posdig.resize(2*n,false);
      vector<vector<string>> res;
      dfs(board,res,0);
      return res;  
    }
};
