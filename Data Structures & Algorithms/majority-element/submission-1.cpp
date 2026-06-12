class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxElem = nums[0];
        int freq = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] != maxElem){
                if(freq==0){
                    maxElem = nums[i];
                    freq=1;
                }
                else{
                    freq--;
                }
            }
            else{
                freq++;
            }
        }
        return maxElem;
    }
};