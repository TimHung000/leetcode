#include <stdint.h>


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n)
        {
            if(n & (unsigned int)1)
                ++res;
            n = n >> 1;
        }
        return res;
    }

    // n & (n - 1) drops the lowest set bit. It's a neat little bit trick.
    // Let's use n = 00101100 as an example. This binary representation has three 1s.
    // If n = 00101100, then n - 1 = 00101011, so n & (n - 1) = 00101100 & 00101011 = 00101000. Count = 1.
    // If n = 00101000, then n - 1 = 00100111, so n & (n - 1) = 00101000 & 00100111 = 00100000. Count = 2.
    // If n = 00100000, then n - 1 = 00011111, so n & (n - 1) = 00100000 & 00011111 = 00000000. Count = 3.
    // n is now zero, so the while loop ends, and the final count (the numbers of set bits) is returned.
    int hammingWeight1(uint32_t n) {
        int count = 0;
        
        while (n) {
            n &= (n - 1);
            count++;
        }
        
        return count;
    }
};