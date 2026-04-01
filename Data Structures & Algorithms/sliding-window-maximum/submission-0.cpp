class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        for(int i=0;i<k;i++){
            int buff = nums[i];
            while(!dq.empty() && dq.back().first < buff){
                dq.pop_back();
            }
            dq.push_back({buff,i});
        }
        vector<int> ans;
        ans.push_back(dq.front().first);
        for(int i=k;i<nums.size();i++){
            int buff = nums[i];
            while((!dq.empty() && dq.back().first < buff)){
                dq.pop_back();
            }
            while(!dq.empty() && dq.front().second <= i-k){
                dq.pop_front();
            }
            dq.push_back({buff,i});
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};
