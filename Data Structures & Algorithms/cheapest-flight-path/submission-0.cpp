class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n,INT_MAX);
        cost[src] = 0;
        for(int i=0;i<=k;i++){
            vector<int> temp = cost;
            for(const auto &flight : flights ){
                int s = flight[0];
                int d = flight[1];
                int c = flight[2];
                if(cost[s] != INT_MAX && temp[d] > cost[s]+c){
                    temp[d]= cost[s]+c;
                }
            }
            cost = temp;
        }
        return cost[dst]!=INT_MAX ? cost[dst] : -1;
    }
};
