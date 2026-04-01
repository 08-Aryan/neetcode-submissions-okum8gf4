class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;
        for(auto time:times){
           edges[time[0]].push_back( { time[1], time[2] } ); 
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,k});
        set<int> visited;
        int t = 0;
        vector<int> ans(n+1,INT_MAX);
        ans[k]=0;
        while(!minHeap.empty()){
            auto [ wieght , node ] = minHeap.top();
            minHeap.pop();
            if(visited.count(node)){
                continue;
            }
            visited.insert(node);
            t = wieght;
            for(auto [nie,currwieght]: edges[node]){
                ans[nie] = min(ans[nie],wieght+currwieght);
                minHeap.push({ans[nie],nie});
            }

        }
        return visited.size()==n?t:-1;
    }
};
