class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // Use a set for O(1) dictionary lookups and visited tracking
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        if (dict.count(beginWord)) {
            dict.erase(beginWord);
        }

        int res = 1; 

        while(!q.empty()){
            int s = q.size();
            
            for(int i = 0; i < s; ++i){
                string currentWord = q.front();
                q.pop();

                if(currentWord == endWord){
                    return res;
                }
                
                string nextWord = currentWord;
                
                // O(L * 26) optimization: Generate all neighbors on-the-fly
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = nextWord[j];
                    
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        
                        if (dict.count(nextWord)) {
                            q.push(nextWord);
                            dict.erase(nextWord); // Mark as visited
                        }
                    }
                    
                    nextWord[j] = originalChar;
                }
            }
            res++;
        }
        
        return 0;
    }
};
