class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for( int i = 0;i<nums.size();i++){
            int num = nums[i];
            int need = target - num;
            if(seen.find(need) != seen.end()){
                return {seen[need],i};
            }
            seen[num] = i;
        }
        return {-1,-1};
        
    }
};
