class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(auto task:tasks){
            int ch = task-'A';
            count[ch]++;
        }
        
        sort(count.begin(),count.end());
        int maxf = count[25];
        int idle = (maxf-1)*n;
        // removing positions which are used up
        for(int i=24;i>=0;i--){
            idle -= min(maxf-1,count[i]);
        }
        return max(0,idle) + tasks.size(); 
    }
};
