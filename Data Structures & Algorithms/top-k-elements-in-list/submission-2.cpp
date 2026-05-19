typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        priority_queue<pii,vector<pii>,greater<pii>> freq;
        for(auto [key,cnt]: count){
            freq.push({cnt,key});
            if(freq.size() > k){
                freq.pop();
            }
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq.top().second);
            freq.pop();
        }
        return ans;

    }
};
