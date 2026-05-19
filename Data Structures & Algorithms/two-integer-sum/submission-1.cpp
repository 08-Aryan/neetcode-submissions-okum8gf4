class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> have;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(have.count(target-x)){
                return {have[target-x],i};
            }
            else{
                have[x] = i;
            }
        }
        return {-1,-1};
    }
};
