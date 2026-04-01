class Solution {
    int m,n;
    vector<vector<int>> dp;
public:
    bool dfs(string &s,int i,string &p,int j){
        if(j==n){
            return i==m;
        }
        bool curr = (i<m && (s[i]==p[j]||p[j]=='.'));
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // if next * then search for 0 to n times the element
        if(j+1 < n && p[j+1]=='*'){
            return dp[i][j]=dfs(s,i,p,j+2) || (curr && dfs(s,i+1,p,j));
        }
        if(curr){
            return dp[i][j]=dfs(s,i+1,p,j+1);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return dfs(s,0,p,0);
    }
};
