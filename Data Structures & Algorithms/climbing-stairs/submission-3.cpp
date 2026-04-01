class Solution {
public:
    int climbStairs(int n) {
        int first = 1;
        int second = 1;
        for(int i=n-2;i>=0;i--){
            first = first + second;
            second = first - second; 
        }
        return first;
    }
};
