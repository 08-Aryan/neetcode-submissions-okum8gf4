/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
struct comp{
    bool operator()(Interval &a,Interval &b){
        return a.start < b.start;
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n<2){
            return true;
        }
        sort(intervals.begin(),intervals.end(),comp());
        
        for(int i=1;i<n;i++){
            if(intervals[i-1].end > intervals[i].start){
                return false;
            }
        }
        return true;
    }
};
