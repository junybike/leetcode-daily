class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int bits[24];  // To store the frequency of bits for all numbers in 'candidate'.
                       // For example, if there is a 5 in 'candidates', increment bits[0] and bits[2],
                       // since 5 has a 1 bit on the first and third bit.
        
        int index = 0; // To track the location of bits.
        for (int i : candidates)
        {
            while (i != 0) 
            {
                // Check the right most bit. 
                // If it is 1, increment the bits according to the position of the bit (index)
                if (i & 1 != 0) bits[index]++;   

                index++;                // updating the position of bit to check
                i = unsigned(i) >> 1;   // shifting the binary representation of the current number to compare the next bit 
            }
            index = 0;  // reset position of bit
        }
        
        index = 0;  // use this variable to find the max number of common bit location in 'bits'
        for (int i = 0; i < 24; i++)
        {
            if (bits[i] > index) index = bits[i];
        }

        // By getting the largest frequency of bit location, we can determine the largest amount of combination of numbers.
        return index;
    }
};
