class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int bfs(int r,int c,vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visiteed(n,vector<int>(m,-1));
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()){
            int x = q.size();
            while(x>0){
                auto [row,col]=q.front();
                q.pop();
                for(const auto &d:dir){
                    int nr = row + d[0];
                    int nc = col + d[1];
                    if(nr<0 || nc < 0 || nr >= n || nc >= m || matrix[nr][nc] <= matrix[row][col]){
                        continue;
                    }
                    else{
                        q.push({nr,nc});
                    }
                }
                x--;
            }
            ans++;

        }
        return ans;
    }
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visiteed(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j =0 ; j<m ;j++){
                int ans = bfs(i,j,matrix);
                res = max(ans,res);
            }
        }
        return res;
    }
};
