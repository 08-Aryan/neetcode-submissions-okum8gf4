class Solution {
    int getTop(stack<int> &stk){
        if(stk.empty()){
            return -200;
        }
        int top = stk.top();
        stk.pop();
        return top;
    }
    int process(string s,int first,int second){
        if(s == "+"){
            return first + second;
        }
        if(s == "-"){
            return first - second;
        }
        if(s == "*"){
            return first * second;
        }
        return first / second;
    }
    void handleOperator(string s,stack<int> &stk){
        int second = getTop(stk);
        int first = getTop(stk);
        int ans = process(s,first,second);
        stk.push(ans);
    }

    bool isOperator(string s){
        return s == "+" || s== "-" || s== "*" || s== "/";
    }
    int getNum(string s){
        int ans = 0;
        int i = 0;
        int sign = 1;
        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        for(;i<s.size();i++){
            ans *= 10;
            ans += s[i]-'0';
        }
        return ans * sign;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s : tokens){
            if(isOperator(s)){
                handleOperator(s,stk);
            }
            else{
                int num = getNum(s);
                stk.push(num);
            }
        }
        return stk.top();
    }
};
