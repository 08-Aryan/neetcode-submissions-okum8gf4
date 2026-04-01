class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int total = 0;

        for(string &op : operations){
            
            if(op == "C"){
                total -= st.top();
                st.pop();
            }
            else if(op == "D"){
                int val = st.top() * 2;
                st.push(val);
                total += val;
            }
            else if(op == "+"){
                int first = st.top(); st.pop();
                int second = st.top();
                st.push(first);
                int sum = first + second;
                st.push(sum);
                total += sum;
            }
            else{
                int val = stoi(op);
                st.push(val);
                total += val;
            }
        }

        return total;
    }
};