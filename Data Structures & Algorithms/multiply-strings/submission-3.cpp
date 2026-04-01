class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2=="0"){
            return "0";
        }
        int n1 = num1.size(),n2 = num2.size();
        vector<int> ans(n1+n2,0);
        for(int i=n2-1;i>=0;i--){
           
            for(int j=n1-1;j>=0;j--){
                int mul = (num1[j]-'0') * (num2[i]-'0');
                int sum = mul+ans[i+j+1];
                ans[i+j+1] = sum %10;
                ans [i+j] += sum/10;
            }
        }
        string result;
        int i =0;
        while(ans[i]==0){
            i++;
        }
        for(;i<n1+n2;i++){
            
            
                char ch = ans[i] + '0';
                result += ch;
            


        }
        return result;
    }
};
