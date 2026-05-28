struct comp{
    bool operator()(const pair<int,int> a,const pair<int,int> b){
        return a.first > b.first;
    }

};
class Solution {
    
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> info;
        for(int i = 0;i<n;i++){
            info.push_back({position[i],speed[i]});
        }
        sort(info.begin(),info.end(),comp());
        int fleets = 1;
        double prevTime = (double)(target - info[0].first)/info[0].second;
        for(int i = 1;i<n;i++){
            double currTime = (double)(target - info[i].first)/info[i].second;
            if(currTime > prevTime){
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
