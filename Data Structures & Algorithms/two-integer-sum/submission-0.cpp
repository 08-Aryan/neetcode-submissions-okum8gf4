class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> val;
        int n = nums.size();
        for(auto i=0;i<n;i++){
            if(val.find(target-nums[i])!=val.end()){
                return {val[target-nums[i]],i};
            }
            else{
                val[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};