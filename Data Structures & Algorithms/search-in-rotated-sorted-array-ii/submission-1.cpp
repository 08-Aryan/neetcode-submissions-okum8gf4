class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            int num = nums[mid];
            if(num == target){
                return true;
            }
            if(nums[l] == num && nums[r] == num){
                l++,r--;
            }
            if( nums[l] <= num){
                if(nums[l] <= target && num > target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                } 
            }
            else{
                if(nums[r] >= target && num < target){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
        }
        return false;
    }
};