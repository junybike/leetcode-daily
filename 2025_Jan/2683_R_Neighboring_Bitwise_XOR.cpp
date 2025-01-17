// 2025 Jan 17

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        // If the bitwise xor sum of all bits are 0, then it is possible to generate the original array.
        // In original array, must use each element twice to construct the derived array.
        // Can be determined whether each elements were used twice by XORing all values and obtain 0. (a XOR a = 0)  
      
        short xor_sum = -1;
        for (int& i : derived)
        {
            if (xor_sum == -1) xor_sum = i;
            else xor_sum = xor_sum ^ i;
        }
        return (xor_sum == 0);
    }
};
/*
solution reference
https://leetcode.com/problems/neighboring-bitwise-xor/solutions/6291527/c-py3-1-liner-beats-100
*/

