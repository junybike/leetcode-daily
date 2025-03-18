// 2025 Mar 18

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int bit = 0;        // to track 'bit' & some other bit for some values in 'nums'
        int L = 0;          // window left-most bound
        int ans = 0;        // longest subarray size

        for (int R = 0; R < nums.size(); R++)
        {
            while (bit & nums[R] != 0)  // while the bit & some number is not 0,
            {
                bit = bit ^ nums[L];    // removes the leftmost bit
                L++;                    // shrinks the window size
            }
            bit = bit | nums[R];        // add the next value

            if (ans < R - L + 1) ans = R - L + 1;   // update the longest subarray size
        }

        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/longest-nice-subarray/editorial
*/
