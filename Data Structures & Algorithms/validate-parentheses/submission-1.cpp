class Solution {
public:
    unordered_map<char,char> openClose = {{'{','}'},{'(',')'},{'[',']'}};
    bool handleClosing(char ch,stack<char> &stk){
        if(stk.empty()){
            return false;
        }
        char top = stk.top();
        char need = openClose[top];
        stk.pop();
        return need == ch;
    }
    bool isClosing(char ch){
        return (ch == ')') || (ch == '}') || (ch==']');
    }
    bool isValid(string s) {
        stack<char> stk;
        for(char ch:s){
            if(isClosing(ch)){
                if(!handleClosing(ch,stk)){
                    return false;
                }
            }
            else{
                stk.push(ch);
            }
        }
        return stk.size()==0;
    }
};
