class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxsize = 0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i < 3 || dp[i+1][j-1]==1)){
                    dp[i][j]=1;
                    int size = j-i+1;
                    if(maxsize<size){
                        maxsize = size;
                         start=i;
                    }
                }
            }
        }
        return s.substr(start,maxsize);
     }
};
