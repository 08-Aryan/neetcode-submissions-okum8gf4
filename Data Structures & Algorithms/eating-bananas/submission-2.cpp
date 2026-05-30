class Solution {
    bool isPossible(int rate,vector<int> & piles,int h){
        int time = 0;
        for(int pile:piles){
            time += pile/rate;
            if(pile%rate){
                time++;
            }
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minRate = 1;
        int maxRate = 0;
        for(int i=0;i < piles.size();i++){
            maxRate = max(maxRate,piles[i]);
        }
        while(minRate < maxRate){
            int mid = minRate + (maxRate - minRate)/2;
            if(isPossible(mid,piles,h)){
                maxRate = mid;
            }
            else{
                minRate = mid+1;
            }
        }
        return minRate;
    }
};
