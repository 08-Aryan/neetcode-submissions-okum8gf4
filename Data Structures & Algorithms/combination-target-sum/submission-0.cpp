class Solution {
    vector<vector<int>> sol;
public:
    void traversal(vector<int> &nums,int target,vector<int> &curr,int ind){
        if(target == 0){
            sol.push_back(curr);
            return;
        }
        if(target < 0 || ind >=nums.size()){
            return;
        }
        curr.push_back(nums[ind]);
        traversal(nums,target-nums[ind],curr,ind);
        curr.pop_back();
        traversal(nums,target,curr,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        traversal(nums,target,curr,0);
        return sol;
        
    }
};
