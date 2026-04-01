class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(),n2 = word2.size();
        string ans = "";
        int larger = max(n1 , n2);
        for(int i=0;i<larger;i++){
            if(i < n1 ){
                ans += word1[i];
            }
            if(i < n2){
                ans += word2[i];
            }
        }
        return ans;
    }
};