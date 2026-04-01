class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        // getting all tresure 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto d:dir){
                int r = row+d.first;
                int c = col+d.second;
                if(r < 0 || r >=grid.size() || c < 0 || c >= grid[0].size() || grid[r][c]!=INT_MAX){
                    continue;
                }
                grid[r][c]= grid[row][col]+1;
                q.push({r,c});
            }

        }
    

    }
};
