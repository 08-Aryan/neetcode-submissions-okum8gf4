class Solution {
public:
    bool dfs(vector<vector<char>> &board,int r, int c, string word,int l){
        if(l==word.size()){
            return true;
        }
        if(r<0 || c>=board[0].size() || r>=board.size() || c < 0 || board[r][c]!=word[l] || board[r][c]=='#'){
            return false;
        }
        board[r][c] = '#';
        bool res = dfs(board,r+1,c,word,l+1) || dfs(board,r-1,c,word,l+1) || dfs(board,r,c-1,word,l+1) || dfs(board,r,c+1,word,l+1);
        board[r][c] = word[l];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(dfs(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
