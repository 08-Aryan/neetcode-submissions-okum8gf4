class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int n = 0;
        for(int i=0;i<32;i++){
            int x = (a>>i) & (1);
            int y = (b>>i) & (1);
            int sum = carry + x + y;
            if(sum == 0){
                carry = 0;
            }
            else if(sum == 1){
                carry = 0;
                n = n | (1<<i);
            }
            else if(sum == 2){
                carry = 1;
            }
            else{
                carry = 1;
                n = n | (1<<i);
            }

        }
        return n;
    }
};
