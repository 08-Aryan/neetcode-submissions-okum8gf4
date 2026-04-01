class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<int> &subset,vector<int>& nums,int i){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(ans,subset,nums,i+1);
        subset.pop_back();
        dfs(ans,subset,nums,i+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(ans,subset,nums,0);
        return ans;
        
    }
};
