class Solution {
public:
    vector<int> freq(string s){
        vector<int> occ(26,0);
        for(auto ch:s){
            occ[ch-'a']++;
        }
        return occ;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> result;
        for(auto str:strs){
            result[freq(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto pair:result){
            ans.push_back(pair.second);
        }
        return ans;
    }
};