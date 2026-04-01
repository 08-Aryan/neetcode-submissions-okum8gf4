class Solution {
public:
    int dfs(vector<int> &nums,int target,int idx){
        if(idx==nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        int add = dfs(nums,target-nums[idx],idx+1);
        int substract = dfs(nums,target+nums[idx],idx+1);
        return add+substract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,target,0);
    }
};
