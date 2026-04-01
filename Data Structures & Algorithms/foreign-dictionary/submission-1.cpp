class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> mpp;
        unordered_map<char,int> indegree;
        if(words.size()==1){
            return words[0];
        }
        for(int i=0;i<words.size();i++){
            for(auto ch:words[i]){
                mpp[ch]=unordered_set<char>();
                indegree[ch]=0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2= words[i+1];
            int minlen = min(word1.size(),word2.size());
            if(word1.size() > word2.size() && word1.substr(0,minlen)==word2.substr(0,minlen)){
                return "";
            }
            for(int j=0;j<minlen;j++){
                if(word1[j]!=word2[j]){
                    if(mpp[word1[j]].find(word2[j]) == mpp[word1[j]].end()){
                        mpp[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }

        }
        queue<char> q;
        for(auto [ch,num]:indegree){
            if(num==0){
                q.push(ch);
            }
        }
        string ans = "";
        while(!q.empty()){
            char ch = q.front();
            ans += ch;
            q.pop();
            for(auto &nie:mpp[ch]){
                indegree[nie]--;
                if(indegree[nie]==0){
                    q.push(nie);
                }
            }
        }
        return ans.size()==indegree.size() ? ans:"";
        
    }
};
