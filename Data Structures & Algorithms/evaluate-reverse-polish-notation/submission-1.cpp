class Solution {
public:
    int stoi(string s){
        int i=0;
        int sign = 1;
        if(s[i]=='-'){
            sign = -1;
            i = 1;
        }
        int ans = 0;
        for(;i<s.size();i++){
            ans*=10;
            ans+= s[i]-'0';
        }
        return ans*sign;
    }
    bool isOperator(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/"){
            return true;
        }
        return false;
    }
    bool manager(stack<int> &stk,string s){
        if(stk.size()<2){
            return false;
        }
        int first = stk.top();
        stk.pop();
        int second = stk.top();
        stk.pop();
        if(s =="+"){
            stk.push(first+second);
        }
        else if(s=="-"){
            stk.push(second-first);
        }
        else if(s=="*"){
             stk.push(first*second);
        }
        else if(s=="/"){
             stk.push(second/first);
        }
        return true;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
                 if(!manager(stk,tokens[i])){
                    return INT_MIN;
                 }
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.size()==1?stk.top():INT_MIN;
    }
};
