// 2024 Dec 7

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int L = 1;                                      // Lowest value possible
        int R = *max_element(nums.begin(), nums.end()); // Maximum value in 'nums'

        // Performs binary search
        while (L < R)
        {
            int M = L + (R - L) / 2;    // The number of bag to be made after split: the middle value between L and R
            int op = 0;                 // To count the number of operation

            // Calculate the number of operation
            for (int i : nums)
            {                
                op = op + ((i - 1) / M);        // Keep track of number of operation made
                if (op > maxOperations) break;  // The case when 'op' exceeds the 'maxOperations'. 
            }

            // If 'op' is lower than 'maxOperation',
            // shrink the range by updating 'R' with the number of operation made 
            if (op <= maxOperations)
            {
                R = M;
            }
            // Else, shrink the range by updating 'L' to 'M + 1' 
            else L = M + 1;
        }
        return R;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/solutions/6121496/video-short-simple-explained-step-by-step
*/
