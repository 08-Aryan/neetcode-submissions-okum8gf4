class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> networkMap;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        vector<int> timetaken(n+1, INT_MAX);
        set<int> visited;

        for(auto &t : times){
            int s = t[0], d = t[1], w = t[2];
            networkMap[s].push_back({d, w});
        }

        minHeap.push({0, k});
        timetaken[k] = 0;

        int mintime = 0;

        while(!minHeap.empty()){
            auto [wi, node] = minHeap.top();
            minHeap.pop();

            if(visited.count(node)) continue;

            visited.insert(node);
            mintime = wi;

            for(auto [node2, wj] : networkMap[node]){
                if(wi + wj < timetaken[node2]){
                    timetaken[node2] = wi + wj;
                    minHeap.push({timetaken[node2], node2});
                }
            }
        }

        return visited.size() == n ? mintime : -1;
    }
};
