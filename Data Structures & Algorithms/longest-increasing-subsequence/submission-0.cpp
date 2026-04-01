class Solution {
public:
    int dfs(vector<int> nums,int ind,int ub){
        if(ind >=nums.size()){
            return 0;
        }
        int count = dfs(nums,ind+1,ub);
        if(ub< nums[ind]){
            count = max(count,1+dfs(nums,ind+1,nums[ind]));
        }
        
        return count;
    }
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums,0,INT_MIN);
    }
};
