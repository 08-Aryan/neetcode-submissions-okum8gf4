class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        int n = nums.size();
        // Inset unique in set
        for(int i=0;i<n;i++){
            if(unique.find(nums[i])!= unique.end()){
                return true;
            }
            unique.insert(nums[i]);
        }
        int m = unique.size();
        // Check if set size is smaller than n 
        return false;
    }
};