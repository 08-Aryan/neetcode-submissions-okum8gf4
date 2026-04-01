class Solution {
    void swap(int l,int r , vector<int> & nums){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = nums[l];
    }
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                swap(l,i,nums);
                l++;
            }
        }
        return l;
    }
};