class Solution {
public:
    bool boxValid(vector<vector<char>>&board,char ch,int r,int c){
        int startRow = (r/3)*3;
        int startCol = (c/3)*3;
        for(int i=startRow;i<startRow+3;i++){
            for(int j=startCol;j<startCol+3;j++){
                if(r==i && c==j){
                    continue;
                }
                if(board[i][j]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool colValid(vector<vector<char>>&board,char ch,int r,int c){
        for(int i=0;i<board.size();i++){
            if(i==r){
                continue;
            }
            if(board[i][c]==ch){
                return false;
            }
        }
        return true;
    }
    bool rowValid(vector<vector<char>>&board,char ch,int r,int c){
        for(int i=0;i<c;i++){
            if(i==c){
                continue;
            }
            if(board[r][i]==ch){
                return false;
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>&board,char ch,int r,int c){
        return rowValid(board,ch,r,c)&&boxValid(board,ch,r,c)&&colValid(board,ch,r,c);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char ch = board[i][j];
                if(ch == '.'){
                    continue;
                }
                if(!isValid(board,ch,i,j)){
                    return false;
                }

            }
        }
        return true;
    }
};
