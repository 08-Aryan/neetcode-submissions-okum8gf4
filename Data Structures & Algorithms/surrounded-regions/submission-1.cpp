class Solution {
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int Row,Col;
    void capture(vector<vector<char>>& board){
        queue<pair<int,int>> q;
        for(int r = 0; r < Row ; r++){
            for(int c = 0; c < Col ; c++){
                if((r == 0 || r == Row-1 || c == 0 || c == Col-1)&&(board[r][c]=='O')){
                    q.push({r,c});
                    board[r][c] = 'S';
                }
            }
        }
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            
            for(auto &d: directions){
                int r = row + d[0];
                int c = col + d[1];
                if(r >= 0 && c >= 0 && r < Row && c < Col && board[r][c]=='O' ){
                    q.push({r,c});
                    board[r][c] = 'S';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        Row = board.size();
        Col = board[0].size();
        
        // Capture the board with X where not possible to escape
        capture(board);

        for(int r = 0; r < Row ; r++){
            for(int c = 0; c < Col ; c++){
                if(board[r][c] == 'S'){
                    board[r][c] = 'O';
                }
                else if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }
        
    }
};
