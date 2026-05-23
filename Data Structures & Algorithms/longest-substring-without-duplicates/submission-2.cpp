class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> lastseen;
        for(int i=0;i<n;i++){
            char x = s[i];
            if(lastseen.count(x) && lastseen[x] >= l){
                l = lastseen[x]+1;
            }
            else{
                ans = max(ans,i-l+1);
            }
            lastseen[x] = i;

        }
        return ans;
    }
};
