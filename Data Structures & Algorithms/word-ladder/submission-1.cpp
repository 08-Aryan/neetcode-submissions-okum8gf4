#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1. REMOVED: hammingdistance function is no longer needed.
    // 2. REMOVED: hamming function is no longer needed.

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // Change 1: Use an unordered_set for O(1) dictionary lookups.
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // Initial check: The end word MUST exist in the set.
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        // Change 2: The adjacency list (hm_is_1) and 'visited' map 
        // are no longer needed, as we track visited nodes by erasing from the 'dict'.

        queue<string> q;
        q.push(beginWord);
        
        // Track visited by removing from dict
        if (dict.count(beginWord)) {
            dict.erase(beginWord);
        }

        // The path length starts at 1 (the beginWord itself)
        int res = 1; 

        while(!q.empty()){
            int s = q.size();
            
            for(int i = 0; i < s; ++i){
                string currentWord = q.front();
                q.pop();
                
                // Goal Check
                if(currentWord == endWord){
                    return res;
                }
                
                // Change 3: Generate neighbors on-the-fly (The O(N*L) optimization)
                string nextWord = currentWord;
                
                // Iterate through all character positions (L)
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = nextWord[j];
                    
                    // Try all 26 possible characters
                    for (char c = 'a'; c <= 'z'; ++c) {
                        nextWord[j] = c;
                        
                        // Check 1: Is the transformation a valid word? (O(1) lookup)
                        // Check 2: Has it been visited? (It's not visited if it's still in the set)
                        if (dict.count(nextWord)) {
                            
                            // Found a valid, unvisited neighbor!
                            q.push(nextWord);
                            
                            // Mark as visited by removing it from the set.
                            dict.erase(nextWord);
                        }
                    }
                    
                    // Backtrack: Restore the original character for the next position check
                    nextWord[j] = originalChar;
                }
            }
            // After processing ALL nodes at the current level, increment the distance
            res++;
        }
        
        return 0; // End word not reachable
    }
};
