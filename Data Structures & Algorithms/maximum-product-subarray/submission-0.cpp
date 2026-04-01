class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod = 1;
        int maxprod = 1;
        int ans = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int tmp = maxprod * nums[i];
            maxprod = max(max(maxprod*nums[i],minprod*nums[i]),nums[i]);
            minprod = min(min(tmp,nums[i]*minprod),nums[i]);
            ans = max(maxprod,ans);  
        }
        return ans;
    }
};
