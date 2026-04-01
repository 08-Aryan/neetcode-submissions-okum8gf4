class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int left = 0,right = n-1;
       int leftmax = height[left],rightmax = height[right];
       int ans = 0;
       while(left < right){
        if(leftmax < rightmax){
            left++;
            leftmax = max(height[left],leftmax);
            ans += leftmax - height[left];
        }
        else{
            right--;
            rightmax = max(height[right],rightmax);
            ans += rightmax - height[right];
        }
       }
       return ans;
    }
};
