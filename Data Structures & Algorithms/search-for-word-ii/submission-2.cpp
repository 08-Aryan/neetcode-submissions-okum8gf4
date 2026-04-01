class Trie {
public:
    bool end;
    unordered_map<char, Trie*> children;

    Trie() {
        end = false;
    }

    void addWord(const string& word) {
        Trie* curr = this;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }
};

class Solution {
public:
    unordered_set<string> res;
    vector<vector<bool>> visit;

    void backtrack(vector<vector<char>>& board, int r, int c, Trie* node, string& path) {
        // bounds check
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visit[r][c]) return;

        char ch = board[r][c];
        if (node->children.find(ch) == node->children.end()) return;

        visit[r][c] = true;
        node = node->children[ch];
        path.push_back(ch);

        if (node->end) res.insert(path);

        // explore all 4 directions
        backtrack(board, r + 1, c, node, path);
        backtrack(board, r - 1, c, node, path);
        backtrack(board, r, c + 1, node, path);
        backtrack(board, r, c - 1, node, path);

        // undo (backtrack)
        visit[r][c] = false;
        path.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();

        for (auto& word : words)
            root->addWord(word);

        visit.assign(board.size(), vector<bool>(board[0].size(), false));

        string path = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                backtrack(board, i, j, root, path);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
