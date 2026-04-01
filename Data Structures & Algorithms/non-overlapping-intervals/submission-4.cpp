
class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prevend = INT_MIN;
        int n = intervals.size(),ans=0;
        int i=0;
        while(i<n){
            if(prevend <= intervals[i][0]){
                prevend = intervals[i][1];
            }
            else{
                prevend = min(prevend,intervals[i][1]);
                ans++;
            }
            i++;
        }
        return ans;
    }
};
