class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       int ans = 0;
       stack<int> stk;
       for(int i = 0;i <= n;i++){
         while (!stk.empty() &&
                 (i == n || heights[stk.top()] >= heights[i])){
            int top = heights[stk.top()];
            stk.pop();
            int width = stk.empty() ? i : i-stk.top()-1;
            ans = max(ans , width * top);
        }
        stk.push(i);
       }
       return ans; 
    }
};
