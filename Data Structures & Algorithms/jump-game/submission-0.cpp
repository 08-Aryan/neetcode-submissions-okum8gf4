class Solution {
public:
    bool dfs(vector<int> &nums,int i){
        if(i>=nums.size()-1){
            return true;
        }
        int x = nums[i];
        if(x==0){
            return false;
        }
        for(int j=1;j<=x;j++){
            if(dfs(nums,i+j)){
                return true;
            }
        }
        return false;

    }
    bool canJump(vector<int>& nums) {
        return dfs(nums,0);
        
    }
};
