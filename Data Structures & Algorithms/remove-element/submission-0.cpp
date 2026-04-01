class Solution {
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0,r = 0;
        int n = nums.size();
        while(r < n){
            if(nums[r]==val){
                r++;
                continue;
            }
            swap(nums[l],nums[r]);
            l++,r++;
        }
        return l;
    }
};