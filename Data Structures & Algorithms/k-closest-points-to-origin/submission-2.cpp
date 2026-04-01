class Solution {
public:

    int finddistance(vector<int> point){
        int xdistance = point[0]*point[0];
        int ydistance = point[1]*point[1];
        return xdistance+ydistance;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxheap;
        for(auto point:points){
            int distance = finddistance(point);
            maxheap.push({distance,point});
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        vector<vector<int>> ans;
        while(maxheap.size()){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans; 
    }
};
