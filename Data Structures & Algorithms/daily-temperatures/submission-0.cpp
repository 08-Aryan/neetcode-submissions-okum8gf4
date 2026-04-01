class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> deg;
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            int temp = temperatures[i];
            while(!deg.empty() && deg.top().first < temp){
                auto top = deg.top();
                ans[top.second]=i-top.second;
                deg.pop();
            }
            deg.push({temp,i});
        }
        return ans;

    }
};
