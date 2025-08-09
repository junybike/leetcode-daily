// 2025 Aug 9
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if (n == 0 || n < 0) return false;  // 0 and negatives are not power of two
        while (n != 1)
        {
            if (n % 2 != 0) return false;   // divide the number until 1. If cannot divided by 2, not a power of two
            n /= 2;
        }    
        return true;
    }
};
