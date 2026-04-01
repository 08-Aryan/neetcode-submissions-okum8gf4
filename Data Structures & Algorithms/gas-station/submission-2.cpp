class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totgas=0,totcost=0;
        for(int i=0;i<n;i++){
            totgas += gas[i];
            totcost += cost[i];
        }
        if(totcost > totgas){
            return -1;
        }
        int total = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            total += gas[i]-cost[i];
            if(total < 0){
                total = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};
