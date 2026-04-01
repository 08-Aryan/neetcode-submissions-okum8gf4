class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans=0;
        unordered_map<char,int> freq;
        int maxfreq = 0;
        int i = 0;
        for(int j=0;j<n;j++){
                freq[s[j]]++;
                maxfreq = max(freq[s[j]],maxfreq);
                while(j-i+1-maxfreq > k){
                    freq[s[i]]--;
                    i++; 
                }
                ans = max(j-i+1,ans);
              

        }
        return ans;
    }
};
