class Solution {
public:

    string encode(vector<string>& strs) {
        // TC = O(n) SC = O(n+m)/
        string ans = "";
        for(auto str:strs){
            int n = str.size();
            ans += to_string(n) + '#';
            for(auto ch:str){
                ans += ch;
            }
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        for(int i=0;i<n;){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            i = j+1;
            j = i+length;
            ans.push_back(s.substr(i,length));
            i = j;



        }
        return ans;
    }
};
