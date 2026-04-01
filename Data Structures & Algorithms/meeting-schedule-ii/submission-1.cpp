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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp());
        priority_queue<int,vector<int>,greater<int>> room;
        for(int i=0;i<intervals.size();i++){
            if(room.empty() || (room.top() > intervals[i].start)){
                room.push(intervals[i].end);
            }
            else{
                room.pop();
                room.push(intervals[i].end);
            }
        }
        return room.size();
        
    }
};
