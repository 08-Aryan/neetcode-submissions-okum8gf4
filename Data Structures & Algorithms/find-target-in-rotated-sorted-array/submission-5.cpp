
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = (l + r)/2;
            int num = nums[mid];
            if(num == target){
                return mid;
            }
            if( nums[l] <= num){
                if(num < target || nums[l] > target){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if( num > target || target > nums[r]){
                    r = mid-1;
                }
                else{
                    l = mid + 1;
                }
            }
            
        }
        return -1;
    }
};