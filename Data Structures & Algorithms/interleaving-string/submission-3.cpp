class Solution {
   
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n+m != s3.size()){
            return false;

        }
        vector<bool> dp(m+1,false);
        dp[m] = true;
        for(int i=n;i>=0;i--){
            vector<bool> prev(m+1,false);
            if(i==n){
                prev[m]= true;
            }
            for(int j=m;j>=0;j--){
                if(i < n && s1[i] == s3[i+j] && dp[j] ){
                    prev[j]=true;
                }
                if(j< m && s2[j] == s3[i+j] && prev[j+1]){
                    prev[j]=true;
                }
            }
            dp = prev;
        }
        return dp[0];
        
    }
};

