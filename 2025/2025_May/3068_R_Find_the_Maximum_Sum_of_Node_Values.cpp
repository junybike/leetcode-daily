// 2025 May 23
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        dp[n][1] = 0;       // no operation on odd number of element 
        dp[n][0] = INT_MIN; 

        for (int i = n - 1; i >= 0; i--)    // starts from the back of nums
        {
            for (int isEven = 0; isEven <= 1; isEven++)
            {
                long long performOperation = dp[i + 1][isEven ^ 1] + (nums[i] ^ k); // XOR operation on current element
                long long dontPerform = dp[i + 1][isEven] + nums[i];                // no operation on current element
                dp[i][isEven] = max(performOperation, dontPerform);                 // update with the larger one
            }
        }

        return dp[0][1];    // contains the largest sum
    }
};
/*
solution reference
https://leetcode.com/problems/find-the-maximum-sum-of-node-values/editorial
*/
