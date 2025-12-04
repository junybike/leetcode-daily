// 2024 Nov 10

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int bits[32];       // To store the frequency of bits at each position
        int currentOR = 0;  // Keep tracking of ORed values 
        int left = 0;       // A left index to perform sliding window on the 'nums' vector
        int ans = INT_MAX;  // The subarray size to return (remains INT_MAX if no solution exists)

        // For each values in 'nums'
        for (int right = 0; right < nums.size(); right++)
        {
            currentOR = currentOR | nums[right];    // Update the 'currentOR' by ORing the current value

            // Record the frequency of bits for the current value
            for (int bit = 0; bit < 32; bit++)      
            {
                if (nums[right] & (1 << bit)) bits[bit]++;
            }

            // Perform sliding window. Iterating through from the left index to right index of 'nums'
            // Stop the iteration if the currentOR value is equal or greater than k.
            while (left <= right && currentOR >= k)
            {
                ans = min(ans, right - left + 1);   // Update the length of subarray.

                // To update the currentOR by ORing values from the 'bits' array.
                int updateOR = 0;
                for (int bit = 0; bit < 32; bit++)
                {
                    // Decrement the bits[bit] if the bit is present at the same position with the num[left]
                    // to minimize the amount of bits need to be remembered.
                    if (nums[left] & (1 << bit)) bits[bit]--;

                    // New ORed value according to the bits present in 'bits' array
                    if (bits[bit] > 0) updateOR = updateOR | (1 << bit);
                }

                currentOR = updateOR;   // Update the 'currentOR' value
                left++;                 // To move onto the next value in the window range
            }
        }
        // If the 'ans' still holds INT_MAX, no solution exists. Returns -1
        // Else, return the value of 'ans'.
        return ans == INT_MAX ? -1 : ans;
    }
};

/*
soultion reference
https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/solutions/6028459/easiest-solution-100-beats-brute-force-approach-c-python-java-javascript
*/
