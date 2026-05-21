class Solution {
    bool isAlphanum(char ch){
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            char x = tolower(s[l]);
            char y = tolower(s[r]);
            if(!isAlphanum(x)){
                l++;
                continue;
            }
            if(!isAlphanum(y)){
                r--;
                continue;
            }
            if(x == y){
                l++,r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
