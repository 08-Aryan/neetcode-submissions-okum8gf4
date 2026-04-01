class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> digitmap ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans = {""};
        
        for(int i=0;i<digits.size();i++){
            int digit = digits[i]-'0';
            vector<string> temp;
            for(auto ch : digitmap[digit]){
                int size = ans.size();
                for(int j=0;j<size;j++){
                    string curr = ans[j];
                    temp.push_back(curr+ch);
                }
            }
            ans = temp;
        }

        return ans;
    }
};
