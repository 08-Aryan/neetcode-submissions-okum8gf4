class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<uint> dp(n+1,0);
        // 0 in both so one substring
        dp[n] = 1;
       
        for(int i=m-1;i >=0 ;i--){
            uint prev = 1;
            for(int j = n-1;j>=0;j--){
                uint res = dp[j];
                if(s[i]==t[j]){
                    res += prev;
                }
                prev = dp[j];
                dp[j] = res;
            }
        }
        return dp[0];

    }
};