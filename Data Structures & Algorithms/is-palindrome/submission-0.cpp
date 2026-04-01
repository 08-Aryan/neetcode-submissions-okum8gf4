class Solution {
    
public:
    bool alphanum(char ch){
        return ((ch>='A' && ch<='Z')||(ch>='a' && ch<='z')||(ch>='0' && ch<='9'));
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            while(l<r && !alphanum(s[l])){
                l++;
            }
            while(l<r && !alphanum(s[r])){
              r--;  
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++,r--;
        }
        return true;
    }
};
