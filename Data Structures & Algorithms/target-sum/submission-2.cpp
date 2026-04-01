class Solution {
    vector<vector<int>> dp;
    int totalsum ;
public:
    int dfs(vector<int> &nums,int target,int idx,int sum){
        if(idx==nums.size()){
            if(target==sum){
                return 1;
            }
            return 0;
        }
        if(dp[sum + totalsum][idx]!=-1){
            return dp[sum + totalsum][idx];
        }
        int add = dfs(nums,target,idx+1,sum+nums[idx]);
        int subtract = dfs(nums,target,idx+1,sum - nums[idx]);
        return dp[sum + totalsum][idx]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        totalsum = accumulate(nums.begin(),nums.end(),0);
        dp.resize((2*totalsum)+1,vector<int>(nums.size(),-1));
        return dfs(nums,target,0,0);
    }
};
