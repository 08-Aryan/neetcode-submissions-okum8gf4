class Trie {

    public:
    Trie* children[26];
    bool endofword;
        Trie(){
            for(auto &child:children){
                child = nullptr;
            }
            endofword = false;
        }
};
class PrefixTree {
    Trie* root;
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie* curr = root;
        for(auto ch : word){
            int i = ch - 'a';
            if(curr->children[i]==nullptr){
                curr->children[i]=new Trie();
            }
            curr = curr->children[i];
        }
        curr->endofword = true;
        return;
    }
    
    bool search(string word) {
        Trie* curr = root;
        for(auto ch : word){
            int i = ch - 'a';
            if(curr->children[i]==nullptr){
                return false;
            }
            curr = curr->children[i];
        }
       return curr->endofword ;
        
    }
    
    bool startsWith(string prefix) {
                Trie* curr = root;
        for(auto ch : prefix){
            int i = ch - 'a';
            if(curr->children[i]==nullptr){
                return false;
            }
            curr = curr->children[i];
        }
       return true; 
    }
};
