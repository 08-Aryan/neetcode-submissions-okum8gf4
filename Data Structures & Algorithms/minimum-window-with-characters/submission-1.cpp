class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> countT,window;
        int m = s.size(),n = t.size();
        if( m < n){
            return "";
        }
        int start;
        int minLen = INT_MAX;
        int l = 0;
        
        for(char ch:t){
            countT[ch]++;
        }
        int need = countT.size();
        int have = 0;
        for(int r = 0;r < m ; r++){
            char ch = s[r];
            window[ch]++;
            if(countT.count(ch) && countT[ch] == window[ch]){
                have++;
            }
            while(have == need){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]] ){
                    have--;
                }
                l++;
            }
        }
        if(minLen > m){
            return "";
        }
        string ans;
        for(int i=start;i<start+minLen;i++){
            ans += s[i];
        }
        return ans;
    }
};
