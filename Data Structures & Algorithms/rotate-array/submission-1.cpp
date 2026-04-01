class Solution {
    void swap(int l, int r,vector<int> & nums){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
    void reverse(vector<int> & nums,int start,int end){
        while(start < end){
            swap(start,end,nums);
            start++,end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int e1 = n-k-1;
        int s2 = n-k;
        reverse(nums,0,e1);
        reverse(nums,s2,n-1);
        reverse(nums,0,n-1);
    }
};