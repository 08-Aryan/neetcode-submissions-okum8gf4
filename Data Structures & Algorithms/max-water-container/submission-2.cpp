class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int l = 0;
        int r = heights.size()-1;
        while(l < r){
            int hL = heights[l];
            int hR = heights[r];
            int area = min(hL,hR) * (r-l);
            if(hL < hR){
                l++;
            }
            else{
                r--;
            }
            ans = max(ans,area);
        }
        return ans;
    }
};
