class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m + 1), currdp(m + 1);

        // Base case: word1 exhausted
        for (int j = 0; j <= m; j++) {
            dp[j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--) {
            // Base case: word2 exhausted
            currdp[m] = n - i;

            for (int j = m - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    currdp[j] = dp[j + 1];
                } else {
                    currdp[j] = 1 + min({
                        dp[j],        // delete
                        currdp[j + 1],// insert
                        dp[j + 1]     // replace
                    });
                }
            }

            dp = currdp;
        }

        return dp[0];
    }
};

