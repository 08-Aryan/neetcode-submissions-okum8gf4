class Solution {
    string getKey(string str){
        string key;
        vector<int> freq(26,0);
        for(char &s : str){
            int x = s - 'a';
            freq[x]++;
        }
        for(int i=0;i<26;i++){
            key += to_string(freq[i]) + "#";
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group;
        for(string &s:strs){
            string key = getKey(s);
            group[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &[key,value]: group){
            ans.push_back(value);
        }
        return ans;
    }
};
