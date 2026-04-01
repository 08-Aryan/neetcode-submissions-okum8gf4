class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch:s){
            if(ch == ')' || ch == '}' || ch == ']'){
                if(!st.empty()){
                    char last = st.top();
                    st.pop();
                    if(!((ch == ')' && last == '(')|| (ch == '}' && last == '{') || (ch ==']'&&last=='['))){
                        return false;
                    }
                    
                }
                else{
                return false;
                }
            }
            else{
                st.push(ch);
            }
        }
        return st.empty();
        
    }
};
