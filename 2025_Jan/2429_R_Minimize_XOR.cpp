// 2025 Jan 15

class Solution {
public:

    // Find the positive bit present in 'n'
    unsigned int countSetBits(unsigned int n)
    {
        unsigned int count = 0;
        while (n) 
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) 
    {
        bitset<31> y = num1;                // 'num1' in binary format
        bitset<31> x = 0;                   // to find the minimal number that satisfies the conditions
        int bnum2 = countSetBits(num2);     // number of positive bit present in 'num2'

        // Compute the largest number possible with 'bnum2' positive bits.
        for (int b = 30; bnum2 >= 1 && b >= 0; b--)
        {
            if (y[b])
            {
                x[b] = 1;
                bnum2--;
            }
        }    

        // Change any 0 bits to 1 bit while 'bnum2' is still greater than 0
        // to compute the minimal number that satisfies the condition.
        for (int b = 0; bnum2 >= 1 && b < 31; b++)
        {
            if (x[b] == 0)
            {
                x[b] = 1;
                bnum2--;
            }
        }

        return x.to_ulong();
    }
};

/*
solution reference
https://leetcode.com/problems/minimize-xor/solutions/6281503/popcount-bitset-c-beats-100
*/
