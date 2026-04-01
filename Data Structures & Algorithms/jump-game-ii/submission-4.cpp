class Solution {
    vector<int> dp;

    int dfs(vector<int> &nums, int idx) {
        if (idx >= nums.size() - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int maxJump = nums[idx];
        int ans = INT_MAX;

        for (int step = 1; step <= maxJump; step++) {
            int next = idx + step;
            if (next < nums.size()) {
                int sub = dfs(nums, next);
                if (sub != INT_MAX) {   // 🚨 CRITICAL CHECK
                    ans = min(ans, sub + 1);
                }
            }
        }

        return dp[idx] = ans;
    }

public:
    int jump(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        return dfs(nums, 0);
    }
};

