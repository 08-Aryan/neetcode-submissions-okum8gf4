class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0,slow = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            if(fast == slow){
                return slow;
            }
        }
    }
};
