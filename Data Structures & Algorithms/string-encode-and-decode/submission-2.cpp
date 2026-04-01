class Solution {
    string int_to_str(int n){
        if(n==0){
            return "0";
        }
        string ans = "";
        while(n > 0){
            int ch = n%10;
            char c = '0'+ch;
            ans = c + ans ;
            n = n/10;
        }
        return ans;
    }
    int str_to_int(string &s){
        int n = 0;
        for(const char &c : s){
            n = n*10;
            int num = c - '0';
            n = n + num;
        }
        return n;
    }
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(const string &str:strs){
            int n = str.size();
            string s = int_to_str(n);
            ans += s+'#'+str;
        }
        return ans;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            string str = "";
            while(s[i] != '#'){
                str += s[i];
                i++;
            }
            int len = str_to_int(str);
            str = "";
            i++;
            int j = i;
            while(j<len+i){
                str = str+s[j];
                j++;
            }
            ans.push_back(str);
            i = j;
        }
        return ans;
    }
};
