class Solution {
public:
    int dfs(string word1,int l,string word2,int r){
        if(l==word1.size()){
            return word2.size()-r;
        }
        if(r==word2.size()){
            return word1.size()-l;
        }
        if(word1[l]==word2[r]){
            return dfs(word1,l+1,word2,r+1);
        }
        // insert  delete replace
        int res = min(dfs(word1,l+1,word2,r),dfs(word1,l,word2,r+1));
        return min(res,dfs(word1,l+1,word2,r+1))+1;
        

    }
    int minDistance(string word1, string word2) {
        return dfs(word1,0,word2,0);
    }
};
