class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int l = 0, m = 0;
       unordered_map<char,int> lastseen;
       int maxcount=0,count=0;
       while(m<n){
        if( (lastseen.find(s[m])==lastseen.end())||lastseen[s[m]]< l){
            lastseen[s[m]] = m;
            count++;
            maxcount = max(maxcount,count);
        }
        else{
            count = m-lastseen[s[m]];
            l = lastseen[s[m]]+1;
            lastseen[s[m]] = m;
            
        }
        m++;
       } 
       return maxcount;
    }
};
