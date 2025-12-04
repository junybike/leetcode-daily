// 2024 Oct 17

class Solution {
public:
    int maximumSwap(int num) 
    {
        string snum = to_string(num);  // 'num' in string format 
        char c = '0';                  // to store a greatest value 
        int toswap1 = -1;              // to indicate value at which index should be replaced 
        int n = snum.length();         // length of 'snum'

        for (int i = 0; i < n; i++)
        {
            // Iterate through the 'snum' and find a greater value than a fixed value at snum[i].
            for (int j = i + 1; j < n; j++)
            {  
                // Keeps updating the value until it finds the largest value possible,
                // or find the same greatest value but located further back of 'snum'. 
                // (makes the value larger to swap this one instead of the same value found earlier in iteration)
                if (snum[i] < snum[j] && c <= snum[j]) 
                {
                    c = snum[j];  // save the greatest value so far
                    toswap1 = j;  // save the index of the greatest value
                }
            }
            // If the index is not -1, able to make a swap and return immediately.
            if (toswap1 != -1)
            {
                int temp = snum[toswap1];
                snum[toswap1] = snum[i];
                snum[i] = temp;
                return stoi(snum);
            }
        }  
        // No swaps needed
        return num;
    }
};
