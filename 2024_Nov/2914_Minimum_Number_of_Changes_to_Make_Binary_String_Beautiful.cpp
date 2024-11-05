// 2024 Nov 5

class Solution {
public:
    int minChanges(string s) 
    {
        bool even = true;  // boolean value to check if the status is even
        char bit = s[0];   // previous bit to compare
        int count = 0;     // number of changes to be made

        for (char c : s)
        {
            // If the current character 'c' is not the same as previous bit and
            // the amount of traversed characters are not even number amounut,
            // increment the count.
            if (c != bit && !even) count++; 

            even = !even; // switch the 'even' sign each iteration
            bit = c;      // update the bit each iteration
        }
        return count;
    }
};
