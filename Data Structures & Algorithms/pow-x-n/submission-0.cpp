class Solution {
public:
    double myPow(double x, int n) {
        int divide = 0;
        double ans = 1.0;
        if(n<0){
            divide = 1;
            n *= -1;
        }
        while(n > 0){
            if(divide==1){
                ans = ans/x;
            }
            else{
                ans = ans*x;
            }
            n--;
        }
        return ans;
    }
};
