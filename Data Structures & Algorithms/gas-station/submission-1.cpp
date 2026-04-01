class Solution {
    int n;
public:
    bool dfs(int idx,int available,int start,vector<int>& gas, vector<int>& cost){
        if(idx == start){
            return true;
        }
        
        available = available - cost[idx] + gas[idx];
        return available >= 0 && dfs((idx+1)%n,available,start,gas,cost);
        
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        n = gas.size();
        for(int i=0;i<n;i++){
            if(gas[i]-cost[i]>=0){
                if(dfs((i+1)%n,gas[i]-cost[i],i,gas,cost)){
                    return i;
                }
            }
            
        }
        return -1;
    }
};
