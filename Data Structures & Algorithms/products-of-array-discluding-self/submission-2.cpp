class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProd(nums.size(),1);
        vector<int> rightProd(nums.size(),1);
        int left = 1, right = 1;
        for(int i=0;i<nums.size();i++){
            leftProd[i] = left;
            rightProd[nums.size()-i-1] = right;
            right *= nums[nums.size()-i-1];
            left *= nums[i];
        }
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            ans[i] = rightProd[i] * leftProd[i];
        }
        return ans;
    }
};
