class Solution {
    string getStringNum(int n){
        if(n==0){
            return "0";
        }
        string ans = "";
        while(n > 0){
            int x = n % 10;
            n /= 10;
            char c = x + '0';
            ans = c + ans;
        }
        return ans;
    }
    int getNum(string str){
        int ans = 0;
        for(char ch:str){
            int x = ch - '0';
            ans *= 10;
            ans += x;
        }
        return ans;
    }
public:

    string encode(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        vector<int> sizes;
        string ans = "";
        for( string &s : strs){
            sizes.push_back(s.size());
        }
        int i = 0;
        for(string &s:strs){
            ans += getStringNum(sizes[i]) + "#";
            ans += s;
            i++;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while( i < s.size()){
            int j = i;
            string len="";
            while(s[j]!='#'){

                len += s[j];
                j++;
                
            }
            int length = getNum(len);
            i = j+1;
            string str="";
            for(int k=0;k<length;k++){
                str += s[i];
                i++;
            }
            ans.push_back(str);
        }
        return ans;

    }
};
