class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize = INT_MAX;
        int n = strs.size();
        for(auto &s:strs){
            int size = s.size();
            minSize = minSize > size ? size : minSize;
        }
        string str = "";
        for(int i=0;i<minSize;i++){
            for(int j=1;j<n;j++){
                if(strs[j][i]!=strs[0][i]){
                    return str;
                }
                
            }
            str += strs[0][i];
        }
        return str;
    }
};