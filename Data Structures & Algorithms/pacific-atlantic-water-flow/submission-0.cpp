class Solution {
public:
    vector<vector<int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
    bool atlantic ,pacific;
    void dfs(vector<vector<int>>& heights,int row,int col,int prev){
        if(row<0 || col < 0){
            pacific = true;
            return;
        }
        if(row>=heights.size() || col >=heights[0].size()){
            atlantic = true;
            return;
        }
        if(prev < heights[row][col]){
            return;
        }
        int tmp = heights[row][col];
        heights[row][col]=INT_MAX;
        for(vector<int> id:d){
            dfs(heights,row+id[0],col+id[1],tmp);
            if(pacific && atlantic){
                break;
            }
        }
        heights[row][col]=tmp;
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                atlantic = false;
                pacific = false;
                dfs(heights,r,c,INT_MAX);
                if(atlantic && pacific){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
        
    }
};
