class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dp;
        int maxcount = 0;
        for(auto num:nums){
            if(!dp[num]){
            dp[num] = dp[num-1]+dp[num+1]+1;
            dp[num-dp[num-1]]=dp[num];
            dp[num+dp[num+1]]=dp[num];
            maxcount = max(dp[num],maxcount);
            }

        }
        return maxcount;

       

    }
};