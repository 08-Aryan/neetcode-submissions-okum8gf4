class Solution {
    string getElem(string &path,int &i){
        string cur = "";
        while(i < path.size() ){
            if(path[i]=='/'){
                i++;
                break;
            }
            cur += path[i];
            i++;
        }
        
        return cur;
    }
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string curr;
        int n = path.size();
        for(int i = 0;i<n;){
            curr = getElem(path,i);
            if(curr.empty()){
                continue;
            }
            if(curr == ".."){
                if(!stk.empty()){
                    stk.pop_back();
                }

            }
            else if(curr != "."){
                stk.push_back(curr);
            }
        }
        string res = "";
        for(int i=0;i<stk.size();i++){
            res += ("/" + stk[i]);
        }
        return res.empty() ? "/" : res;

    }
};