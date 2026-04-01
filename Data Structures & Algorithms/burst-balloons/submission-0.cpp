class Solution {
public:
    int backtrack(vector<int> &nums){
        if(nums.size()==2){
            return 0;
        }
        int maxcoins = 0;
        for(int i=1;i<nums.size()-1;i++){
            int coins = nums[i-1]*nums[i]*nums[i+1];
            int n = nums[i];
            nums.erase(nums.begin()+i);
            coins += backtrack(nums);
            maxcoins = max(maxcoins,coins);
            nums.insert(nums.begin()+i,n);
            
        }
        return maxcoins;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // Added 1 front and back
        return backtrack(nums);
    }
};
