class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        // Direct bfs
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto [r,c] = q.front();
                q.pop();

                for(auto d:dir){
                    int row = r+d.first;
                    int col = c + d.second;
                    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col]!=1){
                        continue;
                 
                }
                   q.push({row,col});
                   grid[row][col]=2;
                    fresh--;
                }
                
            }
            if(!q.empty()){
            time++;
            }
            

        }
        return fresh==0?time:-1;
    }
};
