class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int ans = x;
        while(l <= r){
            int mid = l + (r-l)/2;
            if((long long)mid*mid <= x){
                l = mid+1;
                ans = mid;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};