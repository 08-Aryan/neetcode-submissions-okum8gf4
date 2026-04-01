class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;
        vector<int> cnt;

        string curr = "";
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                cnt.push_back(num);
                stk.push_back(curr);
                curr = "";
                num = 0;
            }
            else if (s[i] == ']') {
                string temp = curr;
                int repeat = cnt.back();
                cnt.pop_back();

                curr = stk.back();
                stk.pop_back();

                while (repeat--) {
                    curr += temp;
                }
            }
            else {
                curr += s[i];
            }
        }

        return curr;
    }
};