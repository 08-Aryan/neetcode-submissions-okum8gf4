class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(auto &num:nums){
            
            if(sum < 0){
                sum = 0;
            }
            sum += num;
            maxsum = max(sum,maxsum);
            
        }
        return maxsum;
    }
};
