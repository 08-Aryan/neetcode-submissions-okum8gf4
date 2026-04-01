class Solution {
public:
    bool isPalindrome(string s){
        int low =0;
        int high = s.size()-1;
        while(low <high){
            if(s[low] != s[high]){
                return false;
            }
            low++,high--;
        }
        return true;
    }
    void dfs(string s,vector<string> &sol,vector<vector<string>> &ans,int idx){
        if(idx == s.size()){
            ans.push_back(sol);
            return;
        }
        for(int i=idx;i<s.size();i++){
            string substring = s.substr(idx,i-idx+1);
            if(isPalindrome(substring)){
                sol.push_back(substring);
                dfs(s,sol,ans,i+1);
                sol.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string> sol;
        vector<vector<string>> ans;
        dfs(s,sol,ans,0);
        return ans;
        
    }
};
