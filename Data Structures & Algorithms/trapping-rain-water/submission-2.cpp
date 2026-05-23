class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int leftMax = height[l] , rightMax = height[r];
        int ans = 0;
        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax,height[l]);
                int water = leftMax - height[l];
                ans += water;
            }
            else{
                r--;
                rightMax = max(rightMax,height[r]);
                int water = rightMax - height[r];
                ans += water;
            }
        }
        return ans;
    }
};
