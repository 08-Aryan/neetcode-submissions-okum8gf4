class Solution {
    vector<vector<int>> dp;
    bool dfs(string &s1,int l,string &s2,int r,string &s3,int k){
        if(k==s3.size()){
            return (s1.size()==l && s2.size()==r);
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if(l < s1.size() && s1[l] == s3[k]){
            if(dfs(s1,l+1,s2,r,s3,k+1)){
                return dp[l][r]=true;
            }
        }
        if(r < s2.size() && s2[r] == s3[k]){
            if(dfs(s1,l,s2,r+1,s3,k+1)){
                return dp[l][r]=true;
            }
        }
        return dp[l][r]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n - m > 1  || m-n > 1 || n+m!=s3.size()){
            return false;

        }
        dp.resize(n+1,vector<int>(m+1,-1));
        return dfs(s1,0,s2,0,s3,0);
    }
};
