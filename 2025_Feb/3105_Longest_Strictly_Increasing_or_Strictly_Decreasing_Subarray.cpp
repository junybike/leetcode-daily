// 2025 Feb 3

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        short incr = 1; // streaks for strictly increasing values in 'nums'
        short decr = 1; // streaks for strictly decreasing values in 'nums'
        short ans = 1;  // keep track of the maximum streak of either 'incr' or 'decr'

        for (int i = 0; i < nums.size() - 1; i++)
        {  
            if (nums[i] < nums[i + 1])  // strictly increasing case
            {
                incr++;                     // increase 'incr'
                decr = 1;                   // reset 'decr' to 1
                if (incr > ans) ans = incr; // update 'ans' if 'incr' exceeds ans 
            }
            else if (nums[i] > nums[i + 1]) // strictly decreasing case
            {
                decr++;                     // increase 'decr'
                incr = 1;                   // reset 'incr' to 1
                if (decr > ans) ans = decr; // update 'ans' if 'decr' exceeds ans
            }
            else            // case for the duplicate adjacent values (neither increasing or decreasing)
            {
                incr = 1;   // reset 'incr' to 1
                decr = 1;   // reset 'decr' to 1
            }
        }    

        return ans;
    }
};
