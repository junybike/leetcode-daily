// 2025 Aug 13
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if (n <= 0) return false;  // any number less or equal to 0 cannot be power of three
        while (n > 1)
        {
            if (n % 3 != 0) return false;  // divide until it becomes 1. if not divisible by 3, not a power of three
            n /= 3;
        }    
        return true;
    }
};
