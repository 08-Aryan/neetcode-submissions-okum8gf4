class Solution {
    pair<int,int> moveCenter(string &s,int idx,int maxSize,int start,char mode){
        int l = idx;
        int r = idx;
        if(mode == 'e'){
            r++;
        }
        int n = s.size();
        while(l>=0 && r < n && s[l]==s[r]){
                int size = r - l + 1;
                if(size > maxSize){
                    maxSize = size;
                    start = l;
                }
                l--;
                r++;
        }
        return {maxSize,start};

    }
public:
    string longestPalindrome(string s) {
        int maxSize = -1;
        int start = 0;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            // odd palindrome
            auto [size,begin] = moveCenter(s,i,maxSize,start,'o');
            // even palindrome
            auto [size2,begin2] = moveCenter(s,i,size,begin,'e');
            maxSize = size2;
            start = begin2;

        }
        string ans = "";
        for(int i=0;i<maxSize;i++){
            ans += s[start+i];
        }
        return ans;    
    }
};
