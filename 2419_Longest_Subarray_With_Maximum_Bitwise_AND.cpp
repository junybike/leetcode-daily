// 2024 Sept 14

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int max_len = 0, len = 0;
        int max_val = 0;
        int size = nums.size();

        // Find the max value in 'nums'
        for (int i : nums)
        {
            if (i > max_val) max_val = i;
        }

        for (int i : nums)
        {
            // If value i is the max value, increment the 'len' by 1
            // and check if the len is greater than 'max_len'. Replace the 'max_len' if 'len' is larger.
            if (max_val == i)
            {
                len++;
                if (len > max_len) max_len = len;
            }
            // If value i is not the max value, reset the len to 0.
            else len = 0;
        }

        return max_len;
    }
};
