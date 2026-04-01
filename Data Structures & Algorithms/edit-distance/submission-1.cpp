class Solution {
    vector<vector<int>> dp;
public:
    int dfs(string word1,int l,string word2,int r){
        
        if(l==word1.size()){
            return word2.size()-r;
        }
        if(r==word2.size()){
            return word1.size()-l;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        if(word1[l]==word2[r]){
            return dp[l][r]=dfs(word1,l+1,word2,r+1);
        }
        // insert  delete replace
        int res = min(dfs(word1,l+1,word2,r),dfs(word1,l,word2,r+1));
        return dp[l][r]=min(res,dfs(word1,l+1,word2,r+1))+1;
        

    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int> (word2.size(),-1));
        return dfs(word1,0,word2,0);
    }
};
