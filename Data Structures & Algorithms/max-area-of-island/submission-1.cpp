class Solution {
public:
    int dfs(vector<vector<int>> &grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c >= grid[0].size() || grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        int left = dfs(grid,r-1,c);
        int right = dfs(grid,r+1,c);
        int top = dfs(grid,r,c-1);
        int bottom = dfs(grid,r,c+1);
        return left+right+top+bottom+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans = max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};
