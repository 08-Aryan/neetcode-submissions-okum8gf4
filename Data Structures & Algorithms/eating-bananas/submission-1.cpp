class Solution {
public:
    bool possible(vector<int> &piles,int h,int k){
        int i =0;
        int time = 0;
        while(i<piles.size()){
            int num = piles[i];
            
                time += (num+k-1)/k;
                if(time > h){
                    return false;
                }
            
            i++;
        }
        return time<=h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minBanana = 1,maxBanana = 0;
        for(int i=0;i<piles.size();i++){
            maxBanana = max(maxBanana,piles[i]);
        }
        int ans=-1;
        while(minBanana <= maxBanana){
            int mid = minBanana + (maxBanana-minBanana)/2;
            if(possible(piles,h,mid)){
                ans = mid;
                maxBanana = mid-1;
            }
            else{
                minBanana = mid+1;
            }
        }
        return ans;
        
    }
};
