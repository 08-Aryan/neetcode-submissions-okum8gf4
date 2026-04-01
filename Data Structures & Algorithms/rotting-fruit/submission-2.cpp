class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                    if(grid[i][j]==2){
                        q.push({i,j});
                    }
                
            }
        }
        int cnt = 0;
        int time = 0;
        while(fresh && !q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
               auto [row,col] = q.front();
               q.pop();
               for(auto &d:dir){
                int nr = row + d[0] , nc = col + d[1];
                if(nr<0 || nc < 0 || nc >= n || nr >= m || grid[nr][nc]!=1){
                    continue;
                }
                grid[nr][nc]= 2;
                fresh--;
                q.push({nr,nc});
               }
            }
            time++;
        }
        return fresh==0?time:-1;

    }
};