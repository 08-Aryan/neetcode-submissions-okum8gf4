class Solution {
    int houseRob(vector<int> &nums,int start,int end){
        
        int op1 = 0;
        int op2 = nums[start];
        for(int i=start+1;i<end;i++){
            int newOp = max(op1+nums[i],op2);
            op1 = op2;
            op2 = newOp;
        }
        return op2;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int a = houseRob(nums,0,nums.size()-1);
        int b = houseRob(nums,1,nums.size());
        return max(a,b);
    }
};
