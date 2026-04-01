class Solution {
public:
    int dfs(int m,int n,int i,int j,vector<vector<int>> &dp){
        if( (i == m-1) && (j ==(n-1))){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=dfs(m,n,i+1,j,dp)+dfs(m,n,i,j+1,dp); 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            dp[i][n]=0;
        }
        for(int i=0;i<n;i++){
            dp[m][i]=0;
        }

        return dfs(m,n,0,0,dp);
    }
};
