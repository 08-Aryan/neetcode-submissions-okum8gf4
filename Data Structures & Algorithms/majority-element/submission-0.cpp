class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int cnt = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(majority != nums[i]){
                if(cnt == 0){
                    cnt = 1;
                    majority = nums[i];
                }
                else{
                    cnt--;
                }
            }
            else{
                cnt++;
            }
        }
        return majority;
    }
};