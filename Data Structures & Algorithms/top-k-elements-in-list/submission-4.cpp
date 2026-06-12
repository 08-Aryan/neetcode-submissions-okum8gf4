struct comp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> count;
        for(int num:nums){
            count[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        for(auto &[num,cnt]:count){
            if(pq.size() == k){
                int top = pq.top().second;
                if(top < cnt){
                    pq.pop();
                    pq.push({num,cnt});
                }
            }
            else{
                pq.push({num,cnt});
            }
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            int num = pq.top().first;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};
