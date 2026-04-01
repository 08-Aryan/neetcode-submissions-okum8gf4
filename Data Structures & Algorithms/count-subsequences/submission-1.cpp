class Solution {
    vector<vector<int>> dp;
    int dfs(string &s, int sind,string &t,int tind){
        if(sind==s.size()){
            if(tind==t.size()){
                return 1;
            }
            return 0;
        }
        if(dp[sind][tind]!=-1){
            return dp[sind][tind];
        }
        int ans = dfs(s,sind+1,t,tind);
        if(tind < t.size() && s[sind]==t[tind]){
            // take
            ans += dfs(s,sind+1,t,tind+1);
        }
        return dp[sind][tind]=ans;
    }
public:

    int numDistinct(string s, string t) {
        dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
        return dfs(s,0,t,0);
    }
};
