class Solution:
    """
    in python the range of bits for representing a int value is not 32

    for -2 + 3 = 1
    e.g. 3bits
      110
    + 011
    -----
      001

    e.g. more bits
      1111110
    + 0000011
    ----------
      0001000
    """
    
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        sum = a
        while (b & mask) > 0:
            sum = a ^ b
            b = (a & b) << 1
            a = sum
        if b > 0:
            sum = sum & mask
        
        return sum

Solution().getSum(-1, 1)