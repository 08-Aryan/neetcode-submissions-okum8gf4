class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int minheight=heights[i];
            for(int j=i;j<n;j++){
                minheight=min(minheight,heights[j]);
                int area = minheight*(j-i+1);
                ans = max(ans,area);
            }
            
        }
        return ans;
    }
};
