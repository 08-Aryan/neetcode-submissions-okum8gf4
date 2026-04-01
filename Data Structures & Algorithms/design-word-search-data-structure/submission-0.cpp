class Trie{
    public:
        Trie* children[26];
        bool end;
        Trie(){
            for(auto &child:children){
                child = NULL;
            }
            end = false;
        }
};
class WordDictionary {
    Trie* root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *curr = root;
        for(auto ch :word){
            if(!(curr->children[ch-'a'])){
                curr->children[ch-'a']= new Trie();
            }
            curr=curr->children[ch-'a'];
        }
        curr->end = true; 
    }
    bool dfs(string word,int i,Trie* root){
        Trie *curr = root;
        for(int j=i;j<word.size();j++){
            char ch = word[j];
            if(ch=='.'){
                for(auto *child:curr->children){
                    if(child && dfs(word,j+1,child)){
                        return true;
                    }
                }
                return false;
            }
            else{
            if(!(curr->children[ch-'a'])){
                return false;
            }
            curr=curr->children[ch-'a'];
        }            
    }
    return curr->end;
    }
    bool search(string word) {
       return dfs(word,0,root); 
    }
};
