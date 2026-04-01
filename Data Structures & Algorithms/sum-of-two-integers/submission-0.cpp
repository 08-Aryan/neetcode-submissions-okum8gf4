class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        for(int i=0;i<32;i++){
            left = (a >> i)&1;
            right = (b >> i)&1;
            int res = left+right+carry;
            int val = 0;
            if(res==1){
               val = 1;
               carry = 0;
            }
            if(res==2){
                carry = 1;
            }
            if(res==3){
                carry = 1;
                val = 1;
            }
            ans += (val<<i);
        }
        return ans;
    }
};
