class Solution {
    vector<vector<int>> dp;
public:
    bool dfs(vector<int> nums, int idx,int target){
        if(idx==nums.size()){
            return target==0;
        }
        // target to 0 se bhi kam ho gaya then to galat hi hai ye opt
        if(target < 0){
            return false;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        return dp[idx][target]=dfs(nums,idx+1,target) || dfs(nums,idx+1,target-nums[idx]);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
        if(sum%2==1){
            return false;
        }
        dp.resize(nums.size(),vector<int>(sum/2+1,-1));
        return dfs(nums,0,sum/2);
        
    }
};
