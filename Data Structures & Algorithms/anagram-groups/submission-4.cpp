class Solution {
    string generateKey(string str){
        vector<int> count(26,0);
        for(char ch : str){
            count[ch - 'a']++;
        }
        string key = "";
        for(int i=0;i<26;i++){
            string num = to_string(count[i]);
            key += (num + ",");
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(string &str:strs){
            string key = generateKey(str);
            groups[key].push_back(str);

        }
        vector<vector<string>> ans;
        for( auto [key,grp]: groups){
            ans.push_back(grp);
        }
        return ans;
    }
};
