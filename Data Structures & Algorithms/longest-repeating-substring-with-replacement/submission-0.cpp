class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans=0;
        for(int i =0;i<n;i++){
            unordered_map<char,int> freq;
            int maxfreq = 0;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                maxfreq = max(freq[s[j]],maxfreq);
                if(j-i+1-maxfreq <= k){
                    ans = max(j-i+1,ans);
                }
            }

        }
        return ans;
    }
};
