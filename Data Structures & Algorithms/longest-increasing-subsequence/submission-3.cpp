class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int LIS = 1;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(dp.back() < nums[i]){
                LIS++;
                dp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[idx] = nums[i];
            }
        }
        return LIS;
    }
};
