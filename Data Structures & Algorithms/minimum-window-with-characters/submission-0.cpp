class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>countt,window;
        int m = t.size();
        for(int i=0;i<m;i++){
            countt[t[i]]++;
        }
        int need = countt.size();
        int begin;
        int ans = INT_MAX;
        int l = 0,r=0;
        int n = s.size();
        int have = 0;
        while(r<n){
            window[s[r]]++;
            if(countt.count(s[r]) && countt[s[r]]==window[s[r]]){
                have++;
            }
            while(need==have){
                if(ans > r-l+1){
                    ans = r-l+1;
                    begin = l;
                }
                if(countt.count(s[l]) && countt[s[l]]==window[s[l]]){
                    have--;
                }
                window[s[l]]--;
                l++;
                
            }
            r++;
        }
        return ans==INT_MAX?"":s.substr(begin,ans);
         
    }
};
