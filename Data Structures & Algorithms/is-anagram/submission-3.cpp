class Solution {
   
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26,0);
        int n = s.size(),m = t.size();
        if( n != m){
            return false;
        }
        for(int i = 0;i<n;i++){
            int x = s[i] - 'a';
            int y = t[i] - 'a';
            count[x]++;
            count[y]--;
        }
        for(int i = 0;i<26;i++){
            if(count[i]!= 0){
                return false;
            }
        }
        return true;
    }
};
