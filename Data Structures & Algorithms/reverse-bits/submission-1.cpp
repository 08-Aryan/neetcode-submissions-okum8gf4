class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        for(int i=0;i<32;i++){
            int ch = (n >> i) & 1;
            x = x | (ch << 31-i);

        }
        return x;
    }
};
