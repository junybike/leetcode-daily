// 2024 Sept 11

class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int maxbit = 0b100000000000000000000000000000;  // Maximum bit length in the problem 
        int count = 0;

        while (maxbit > 0)
        {   
            // Check bit by bit by bitmasking. If the two bits unmatch, increment count by 1.
            if (int(maxbit & start) != int(maxbit & goal)) count++;
            // Move the 1 bit in maxbit to the right each iteration 
            maxbit = maxbit >> 1;
        }

        return count;
    }
};
