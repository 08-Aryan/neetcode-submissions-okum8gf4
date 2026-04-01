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
    bool operator()(const Interval &a,const Interval &b)const{
        return a.start < b.start;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &interval:intervals){
            if(!pq.empty()){
                int top = pq.top();
                if(top <= interval.start){
                    pq.pop();
                }
            }
            pq.push(interval.end);
        }
        return pq.size();
        
    }
};
