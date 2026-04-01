class Solution {
    bool isPal(string &s, int start,int end){
        while(start < end){
            if(s[start]!= s[end]){
                return false;
            }
            start++,end--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        
        while(l < r){
            if(s[l] != s[r]){
                return isPal(s,l+1,r) || isPal(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
        
    }
};
