class Solution {
public:

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            int x = nums[i];
            for(int j=x;j>0;j--){
                if(i+j >= nums.size() || dp[i+j]==1){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
        
    }
};
