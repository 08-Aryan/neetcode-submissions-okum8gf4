class Solution {
public:
    vector<int> dp;
    int calcCost(vector<int> &cost,int idx){
        if(idx >= cost.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int cost1 = calcCost(cost,idx+1);
        int cost2 = calcCost(cost,idx+2);
        return  dp[idx] = min(cost1,cost2) + cost[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(),-1);
        int from0 = calcCost(cost,0);
        int from1 = calcCost(cost,1);
        
        return min(from0,from1);
    }
};
