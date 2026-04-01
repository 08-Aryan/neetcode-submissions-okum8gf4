class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(auto task:tasks){
            int ch = task-'A';
            count[ch]++;
        }
        priority_queue<int> maxHeap;
        for(auto cnt:count){
            if(cnt>0){
                maxHeap.push(cnt);
            }
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(maxHeap.size() || q.size()){
            time++;
            if(maxHeap.empty()){
                time = q.front().second;
            }
            else{
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt>0){
                q.push({cnt,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                maxHeap.push({q.front().first});
                q.pop();
            }
        }
        return time;
    }
};
