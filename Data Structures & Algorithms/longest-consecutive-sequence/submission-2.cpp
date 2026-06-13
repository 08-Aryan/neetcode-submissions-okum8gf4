class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i=0;i<nums.size();i++){
            seen.insert(nums[i]);
        }
        int longest = 0;
        for(int num:nums){
            int length = 0;
            if(seen.find(num-1) != seen.end()){
                continue;
            }
            while(seen.find(num) != seen.end()){
                length++;
                longest = max(length,longest);
                num = num + 1;
            }
        }
        return longest;
    }
};
