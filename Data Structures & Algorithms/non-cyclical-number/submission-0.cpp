class Solution {
public:
    int sqaresum(int n){
        int ans = 0;
        while(n>0){
            int digit = n%10;
            ans += digit*digit;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n, fast = sqaresum(n);
        while(slow != fast){
            slow = sqaresum(slow);
            fast = sqaresum(fast);
            fast = sqaresum(fast);

        }
        return fast==1;
    }
};
