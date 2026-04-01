class Solution {
public:
    void dfs(vector<int>& candidates, int target,int i ,vector<int> &sol,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(sol);
        }
        if(target <= 0 || i>=candidates.size()){
            return;
        }
        sol.push_back(candidates[i]);
        dfs(candidates,target-candidates[i],i+1,sol,ans);
        sol.pop_back();
        while(i+1 < candidates.size() && candidates[i]==candidates[i+1]){
            i++;
        }
        dfs(candidates,target,i+1,sol,ans);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,sol,ans);
        return ans;
    }
};
