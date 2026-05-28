class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        vector<int> ans(temperatures.size(),0);
        for(int i = temperatures.size()-1;i>= 0 ; i--){
            while(!stk.empty() && temperatures[i] >= stk.top().first){
                auto [top,idx] = stk.top();
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top().second - i;
            }
            stk.push({temperatures[i],i});
        }
        return ans;
    }
};
