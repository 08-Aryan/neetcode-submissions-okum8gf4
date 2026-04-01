class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        if(size1!=size2){
            return false;
        }
        unordered_map<char,int> count1,count2;
        for(auto i=0;i<size1;i++){
            count1[s[i]]++;
            count2[t[i]]++;
        }
       
        return count1==count2;
        
    }
};