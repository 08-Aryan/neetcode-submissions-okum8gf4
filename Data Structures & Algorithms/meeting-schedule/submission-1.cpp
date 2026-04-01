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
    bool operator()(const Interval &a,const Interval &b){
        if(a.start == b.start){
            return a.end < b.end;
        }
        return a.start < b.start;
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp());
        int n = intervals.size();
        int end = 0;
        for(int i=0;i<n;i++){
            if(intervals[i].start < end){
                return false;
            }
            end = intervals[i].end;
        }
        return true;
    }
};
