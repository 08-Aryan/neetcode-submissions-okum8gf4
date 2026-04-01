class Solution {
    string getinstring(vector<int> & ans){
        string res="";
        int i=0;
        while(i<ans.size() && ans[i]==0){
            i++;
        }
        if(i==ans.size()){
            return "0";
        }
        while(i<ans.size()){
            char ch = ans[i]+'0';
            res += ch;
            i++;
        }
        return res;
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        vector<int> ans(num1.length()+num2.length(),0);
        for(int i= num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                int digit = (num1[i]-'0')*(num2[j]-'0');
                int add = digit + ans[i+j+1];
                ans[i+j+1] = add%10;
                ans[i+j]+= add/10;
            }
        }
        return getinstring(ans);

    }
};
