class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        int n = position.size();
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        double prevtime = (double)(target-car[n-1].first)/car[n-1].second;
        int fleet = 1;
        for(int i=n-2;i>=0;i--){
            double currtime = (double)(target-car[i].first)/car[i].second;
            if(currtime>prevtime){
                fleet++;
                prevtime = currtime;
            }
        }
        return fleet;
    }
};
