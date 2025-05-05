// 2025 May 6 

class Solution {
public:
    int numTilings(int n) 
    {
        // Base cases
        if (n <= 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 5;

        // Set up dp vector and the base cases
        vector<int> dp(n + 1, 0);
        dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = (dp[i - 1] * 2 + long(dp[i - 3])) % int(1e9 + 7);
        }    
        return dp[n];
    }
};

/*
https://leetcode.com/problems/domino-and-tromino-tiling/solutions/6715436/recursion-tabulation-math-bonus-o-1-at-end-with-images-hashmap-c-python-java
*/
