// 2025 Aug 10
class Solution {
public:

    long counter(int n)
    {
        long val = 0;
        for (; n; n /= 10) val += pow(10, n % 10);
        return val;
    }

    bool reorderedPowerOf2(int n) 
    {
        long c = counter(n);
        for (int i = 0; i < 32; i++)
        {
            if (counter(1 << i) == c) return true; // compare all power of 2 (2^0 to 2^31)
        }    
        return false;
    }
};
/*
solution reference
https://leetcode.com/problems/reordered-power-of-2/solutions/149843/c-java-python-straight-forward
*/
