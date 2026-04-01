// struct comp{
//     bool operator()(vector<int> &a,vector<int> &b){
//         if(a[0]<b[0]){
//             return true;
//         }    
//         else if(a[0]==b[0]){
//             return a[1]<b[1];
//         }
//         return false;
//     }
// };
// class Solution {
// public:
//     int dfs(vector<vector<int>>& intervals,int i,int lb){
//         if(i>=intervals.size()){
//             return 0;
//         }
//         int ans = dfs(intervals,i+1,lb);
//         if(lb <= intervals[i][0]){
//             ans = max(ans,1+dfs(intervals,i+1,intervals[i][1]));
//         }
//         return ans;
//     }
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end(),comp());
//         return intervals.size()-dfs(intervals,0,-10000);
//     }
// };
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        return intervals.size() - dfs(intervals, 0, -1);
    }

private:
    int dfs(const vector<vector<int>>& intervals, int i, int prev) {
        if (i == intervals.size()) return 0;
        int res = dfs(intervals, i + 1, prev);
        if (prev == -1 || intervals[prev][1] <= intervals[i][0]) {
            res = max(res, 1 + dfs(intervals, i + 1, i));
        }
        return res;
    }
};
