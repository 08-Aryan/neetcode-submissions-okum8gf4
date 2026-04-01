typedef pair<int,int> pd;
struct customComp {
    bool operator()(pd &a,pd &b){
        return a.second > b.second;
    }
};
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pd,vector<pd>,customComp> heap;
        for(auto num:nums){
            freq[num]++;
        } 
        for(auto pair:freq){
            if(heap.size()==k){
                if(heap.top().second < pair.second){
                    heap.pop();
                    heap.push({pair.first,pair.second});
                }
            }
            else{
            heap.push({pair.first,pair.second});
            }
        }
        vector<int> ans;
        while(!heap.empty()){
            auto peak = heap.top();
            heap.pop();
            ans.push_back(peak.first);
        }
        return ans;
    }
};