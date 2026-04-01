class Solution {
public:
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void dfs(vector<int> &nums,vector<vector<int>> &ans,vector<int> &perm,int ind){
        if(ind==nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i=ind;i<nums.size();i++){

            swap(nums[ind],nums[i]);

            perm.push_back(nums[ind]);
            dfs(nums,ans,perm,ind+1);
            perm.pop_back();
            swap(nums[ind],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        dfs(nums,ans,perm,0);
        return ans;
    }
};
