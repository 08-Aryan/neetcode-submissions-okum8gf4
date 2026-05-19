class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort both TC = > O(nlogn) SC= 1
        // Frequency of all elemets
        if(s.size() != t.size()){
            return false;
        }
        vector<int> freq(26,0);
        for(auto &ch:s){
            int x = ch - 'a';
            freq[x]++;
        }
        for(auto &ch:t){
            int y = ch - 'a';
            freq[y]--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};
