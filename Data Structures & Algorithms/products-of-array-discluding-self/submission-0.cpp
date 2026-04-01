class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        for(int i=0;i<n-1;i++){
            ans[i+1]=ans[i]*nums[i]; 
        }
        int prod = 1;
        for(int i = n-1;i>=0;i--){
            ans[i] *= prod; 
            prod *= nums[i];
            
        }
        
        return ans;
        
    }
};
