
class Solution {
public:
    int dfs(vector<vector<int>>& intervals,int i,int prev){
        if(i>=intervals.size()){
            return 0;
        }
        int ans = dfs(intervals,i+1,prev);
        if(prev==-1 || intervals[prev][1] <= intervals[i][0]){
            ans = max(ans,1+dfs(intervals,i+1,i));
        }
        return ans;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        return intervals.size()-dfs(intervals,0,-1);
    }
};
