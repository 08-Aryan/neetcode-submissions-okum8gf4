class Solution {
    void increment(char ch,vector<int> &ans){
        int x = ch - 'a';
        ans[x]++;
        return;
    }
    void decrement(char ch,vector<int> &ans){
        int x = ch - 'a';
        if(ans[x]){
            ans[x]--;
        }
        return;
    }
    vector<int> createKey(string s){
        vector<int> ans(26,0);
        for(int i=0;i<s.size();i++){
            increment(s[i],ans);
        }
        return ans;
    }
    bool isSame(vector<int> key,vector<int> key2){
        for(int i=0;i<26;i++){
            if(key[i]!=key2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int x = s1.size(),y = s2.size();
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> key = createKey(s1);
        string temp;
        for(int i=0;i<x;i++){
            temp += s2[i];
        }
        vector<int> key2 = createKey(temp);
        int l = 0;
        for(int r=x;r<y;r++){
            if(isSame(key,key2)){
                return true;
            }
            else{
                decrement(s2[l],key2);
                increment(s2[r],key2);
                l++;
            }
        }
        return isSame(key,key2);
    }
};
