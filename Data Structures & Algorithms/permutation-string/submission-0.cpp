class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> freq1(26,0),freq2(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        int match = 0;
        for(int i=0;i<26;i++){
            if(freq1[i]==freq2[i]){
                match++;
            }
        }
        int l = 0;
        for(int r=s1.size();r<s2.size();r++){
            if(match==26){
                return true;
            }
            
            if(freq2[s2[l]-'a'] == freq1[s2[l]-'a']){
                match--;
            }
            if(freq2[s2[l]-'a']-1 == freq1[s2[l]-'a']){
                match++;
            }
            freq2[s2[l]-'a']--;
            l++;
            
            if(freq2[s2[r]-'a']+1 == freq1[s2[r]-'a']){
                match++;
            }
            if(freq2[s2[r]-'a'] == freq1[s2[r]-'a']){
                match--;
            }
            freq2[s2[r]-'a']++;
        }
        return match==26;
    }
};
