struct comp{
    bool operator()(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0){
            return {{}};
        }
        sort(intervals.begin(),intervals.end(),comp());
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=prev[1]){
                prev[1]=max(intervals[i][1],prev[1]);
            }
            else{
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
