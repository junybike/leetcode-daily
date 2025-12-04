// 2024 Dec 31

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        int mod = 1e9 + 7;      // Must return by modulo-ed value if the value is too large
        int dp[100001] = {0};   // To store calculated values during dp iterations
        dp[0] = 1;

        for (int i = 1; i <= high; i++)
        {
            long long ans = 1;

            // Case where the iteration count is larger than 'zero' amount
            // Sum up the previous ways of forming with (i - zero)
            if (i >= zero) ans += dp[i - zero]; 
            
            // Case where the iteration count is larger than 'one' amount. 
            // Sum up the previous ways of forming with (i - one)
            if (i >= one) ans += dp[i - one];   
            
            // Store the number of possible ways to form  
            dp[i] = ans % mod;
        }

        return (dp[high] - dp[low - 1] + mod) % mod;
    }
};
/*
solution reference
https://leetcode.com/problems/count-ways-to-build-good-strings/solutions/6203054/recursive-iterative-dp-c-beats-100-py3-98-83
*/
