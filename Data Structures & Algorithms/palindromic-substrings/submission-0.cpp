class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            //odd length
            int l=i,r=i;
            while(l>=0 && r < n){
                if(s[l]==s[r]){
                    l--,r++;
                    ans++;
                }
                else{
                    break;
                }
            }
            //even length
            l=i,r=i+1;
            while(l>=0 && r < n){
                if(s[l]==s[r]){
                    l--,r++;
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};
