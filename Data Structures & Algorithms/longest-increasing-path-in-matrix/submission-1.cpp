class Solution {
    vector<vector<int>> dir = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix,int row,int col,int prevVal){
        int ROWS = matrix.size(), COLS = matrix[0].size();
        if(row < 0 || row >= ROWS || col < 0 || col >= COLS || matrix[row][col] <= prevVal ){
            return 0;
        }
        int res = 1;
        for(const auto &d:dir){
            res = max(res, dfs(matrix,row+d[0],col+d[1],matrix[row][col])+1);
        }
        return res;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int lip = 0;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                lip = max(lip,dfs(matrix,r,c,-1));
            }
        }
        return lip;
    }
};
