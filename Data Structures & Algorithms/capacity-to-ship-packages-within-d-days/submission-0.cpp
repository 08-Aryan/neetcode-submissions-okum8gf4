class Solution {
    bool isPossible(vector<int> & weights,int cap,int days){
        int i = 0;
        while(i < weights.size() && days > 0){
            int sum = 0;
            while(i < weights.size() && sum+weights[i] <= cap){
                sum += weights[i];
                i++;
            }
            days--;
        }
        return i == weights.size() && days >= 0;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxW = 0;
        for(auto &w:weights){
            maxW = max(maxW,w);
            sum+= w;

        }
        int l = maxW,r = sum;
        while(l < r){
            int cap = l + (r-l)/2;
            if(isPossible(weights,cap,days)){
                r = cap;
            }
            else{
                l = cap+1;
            }
        }
        return l;
    }
};