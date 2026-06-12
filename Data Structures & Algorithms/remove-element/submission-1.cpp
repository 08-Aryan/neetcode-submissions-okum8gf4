class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int piv = 0;
        for(int num:nums){
            if(num==val){
                continue;
            }
            else{
                nums[piv] = num;
                piv++;
            }
        }
        return piv;
    }
};