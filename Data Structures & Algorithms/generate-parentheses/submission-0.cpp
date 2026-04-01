class Solution {
public:
    void dfs(int n,vector<string> &ans,string &sol,int open,int close){
        if(open>n || close>n){
            return ;
        }
        if(open==n && close==n){
            ans.push_back(sol);
            return;
        }
        if(close < open){
            sol.push_back(')');
            dfs(n,ans,sol,open,close+1);
            sol.pop_back();
        }
            sol.push_back('(');
            dfs(n,ans,sol,open+1,close);
            sol.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string sol;
        vector<string> ans;
        dfs(n,ans,sol,0,0);
        return ans;
    }
};
