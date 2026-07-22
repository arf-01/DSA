class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long res=0;
        for(int i=0;i<32 ;i++)
        {
          res+=(pow(2,(31-i))*((n >>i ) & 1));
        }
        return res; 
    }
};
