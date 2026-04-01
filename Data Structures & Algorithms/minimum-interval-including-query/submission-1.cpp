struct comp{
    bool operator()(vector<int> & a , vector<int> &b){
        return a[0]==b[0] ? a[1] > b[1] : a[0] > b[0];
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[0] < b[0];
        });
        unordered_map<int,int> queryMap;
        vector<int> sortedQuery = queries;
        sort(sortedQuery.begin(),sortedQuery.end());
        int i = 0;
        priority_queue<vector<int>,vector<vector<int>>,comp> minHeap;
        for(int q:sortedQuery){
            while(i < intervals.size() && q >= intervals[i][0]){
                int left = intervals[i][0];
                int right = intervals[i][1];
                minHeap.push({right - left + 1,right});
                i++;
            }
            while(!minHeap.empty() && q > minHeap.top()[1]){
                minHeap.pop();
            }
            queryMap[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }
        vector<int> ans;
        for(int &q:queries){
            ans.push_back(queryMap[q]);
        }
        return ans;

    }
};