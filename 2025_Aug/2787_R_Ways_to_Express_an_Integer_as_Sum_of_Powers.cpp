// 2025 Aug 12
class Solution {
public:

    long long mod = 1e9 + 7;

    int numberOfWays(int n, int x) 
    {
        // dp[i][j] = number of ways to choose distinct integers from the first i integers such that their sum of their x-th power is j
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            long long val = pow(i, x);  // current val i^x

            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= val) dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % mod;
            }
        }

        return dp[n][n];
    }
};
/*
solution reference
https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/editorial
*/
