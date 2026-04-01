class Solution {
public:
    int findans(vector<int> &nums,int end,int start){
        int prev1 = 0;
        int prev2 = 0;
        for(int i = start;i<=end;i++){
            int ans = max(prev1 , prev2+nums[i]);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        return max(findans(nums,n-2,0),findans(nums,n-1,1));
    }
};
