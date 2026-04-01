class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
         // sum. and count
         int prefix = 0;
         int ans = 0;
         prefixSum[0] = 1;
        for(auto num:nums){
            prefix += num;
            int diff = prefix - k;
            ans += prefixSum[diff];
            prefixSum[prefix]++;
        }
        return ans;
    }
};