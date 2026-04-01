class Solution {
    int partition(vector<int> &nums,int start,int end ){
        int piv = nums[end];
        int i = start;
        for(int j = start;j < end;j++){
            if(piv > nums[j]){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[end],nums[i]);
        return i;
    }
    void quickSort(vector<int> &nums,int start,int end){
        if(start < end){
        int piv = partition(nums,start,end);
        quickSort(nums,start,piv-1);
        quickSort(nums,piv+1,end);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
};