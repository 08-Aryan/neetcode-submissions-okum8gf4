class Solution {
    vector<vector<int>> dp;
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
        if(sum%2==1){
            return false;
        }
        int target = sum/2;
        dp.resize(nums.size(),vector<int>(target+1,false));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=1;j <= target;j++){
                dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()-1][target];
    }
};
