class Solution {
    int dfs(string &s, int sind,string &t,int tind){
        if(sind==s.size()){
            if(tind==t.size()){
                return 1;
            }
            return 0;
        }
        int ans = dfs(s,sind+1,t,tind);
        if(tind < t.size() && s[sind]==t[tind]){
            // take
            ans += dfs(s,sind+1,t,tind+1);
        }
        return ans;
    }
public:

    int numDistinct(string s, string t) {
        return dfs(s,0,t,0);
    }
};
