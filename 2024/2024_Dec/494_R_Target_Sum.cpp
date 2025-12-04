// 2024 Dec 26

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();                                // The size of "nums"
        int sum = accumulate(nums.begin(), nums.end(), 0);  // The sum of all values in "nums"
        int diff = sum - target;                            // The difference of "sum" and "target"

        if (diff < 0 || diff % 2 != 0) return 0;            // Case where nums cannot reach target
        
        // Divide diff by 2 since every sign change impacts by (2 * value).
        // For example, difference of +5 and -5 is 2 * 5. 
        diff /= 2;

        int dp[21][2001] = {{0}};   // dp[i][j] holds number of ways to reach "j" using the first "i" elements of "nums"
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= diff; j++)
            {
                dp[i][j] = dp[i - 1][j];    // Bring the last iteration calculation

                // Changes the sign to negative when the difference is getting larger than the total sum
                if (j >= nums[i - 1]) dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }

        return dp[n][diff];          
    }
};

/*
solution reference
https://leetcode.com/problems/target-sum/solutions/6187154/2d-dp-solutions-recursion-iteration-beats-100
*/
