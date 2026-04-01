class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> powerset = {{}};
        int idx = 0;
        int prev =0;
        
        for(int i=0;i<nums.size();i++){
            idx = (i>=1 && nums[i]==nums[i-1])?prev:0;
            prev = powerset.size();
            for(int j=idx;j<prev;j++){
                vector<int> subset = powerset[j];
                subset.push_back(nums[i]);
                powerset.push_back(subset);
            }
            
        } 
        return powerset;
    }
};
