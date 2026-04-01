class Solution {
    int compareWords(string &a,string &b){
        int n = a.size();
        int m = b.size();
        int x = min(n,m);
        for(int i=0;i<x;i++){
            if(a[i] != b[i]){
                return i;
            }
        }
        if(n > m){
            return -2;
        }
        return -1;
    }
  public:
    string foreignDictionary(vector<string> &words) {
        // code here
        string ans = "";
        unordered_map<char,vector<char>> alienDict;
        vector<int> indegree(26,-1);
        int n = words.size();
        // O(n*m)
        for(int i=0;i<n;i++){
            for(char ch:words[i]){
                if(indegree[ch-'a']==-1){
                    indegree[ch-'a']=0;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            int x = compareWords(words[i],words[i+1]);
            if(x==-1){
                continue;
            }
            if(x == -2){
                return "";
            }
            char left = words[i][x];
            char right = words[i+1][x];
            
            indegree[right-'a']++;
            alienDict[left].push_back(right);
        }
        queue<char> q;
        for(int i=0;i<26;i++){
            if(indegree[i]==0){
                q.push(i+'a');
            }
        }
        while(!q.empty()){
            char ch = q.front();
            ans += ch;
            q.pop();
            for(auto &c: alienDict[ch]){
                indegree[c-'a']--;
                if(indegree[c-'a']==0){
                    q.push(c);
                }
            }
        }
        
        int totalChars = 0;
        for(int i=0; i<26; i++) if(indegree[i] != -1) totalChars++;
        
        return ans.size() == totalChars ? ans : "";
    }
};