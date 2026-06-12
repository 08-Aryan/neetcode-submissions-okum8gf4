class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minElem = -1;
        int minSize = 201;
        int i = 0;
        for(string &str:strs){
            int len = str.size();
            if(len < minSize){
                minSize = len;
                minElem = i;
            }
            i++;
        }
        string smallest = strs[minElem];
        string ans = "";
        int j = 0;
        for(char ch : smallest){
            for(string &str:strs){
                if(ch != str[j]){
                    return ans;
                }
            }
            ans += ch;
            j++;
        }
        return ans;
    }
};