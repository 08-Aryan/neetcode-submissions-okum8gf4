class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<int> ans;
         vector<int> last(26,-1);
         // get last occurance of all
         for(int i=0;i<s.size();i++){
            int c = s[i] - 'a';
            last[c] = i;
         }
         int r = 0;
         while(r<s.size()){
            int start = r;
            int end = last[s[r]-'a'];
            while(r <= end){
                int c = s[r] - 'a';
                end = max(end,last[c]);
                r++;
            }
            ans.push_back(end-start+1);
         }
        return ans;
    }
};
