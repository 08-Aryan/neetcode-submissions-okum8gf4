class Solution {
public:
    bool checkValidString(string s) {
        int minopen =0 ,maxopen = 0;
        for(auto &ch:s){
            if(ch == '('){
                minopen++;
                maxopen++;
            }
            else if(ch == ')'){
                minopen--;
                maxopen--;
            }
            else{
                //* as )
                minopen--;
                // * as (
                maxopen++;
            }
            if(maxopen < 0){
                return false;
            }
            if(minopen < 0){
                minopen = 0;
            }
        }
        return minopen==0;
    }
};
