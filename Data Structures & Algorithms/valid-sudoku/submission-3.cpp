class Solution {
    
    int calcBox(int r,int c){
        return (r/3)*3 + (c/3);
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> Col(9,0), Row(9,0), Box(9,0);
        for(int r = 0;r<9;r++){
            for(int c = 0; c<9;c++){
                if(board[r][c]=='.'){
                    continue;
                }
                int val = board[r][c] - '1';
                if((Row[r] & (1 << val)) || (Col[c] & (1 << val)) || (Box[calcBox(r,c)] & (1 << val))){
                    return false;
                }
                Row[r] |= (1 << val);
                Col[c] |= (1 << val);
                Box[calcBox(r,c)] |= (1 << val);
            }
        }
        return true;
    }
};
