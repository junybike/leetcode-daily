// 2026 Jan 10
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int n1 = s1.length();
        int n2 = s2.length();

        // base case: dp[n1][n2] = 0, dp[n2][n1] = 0. (means that both substrings are empty. no need to delete anything to make the two equal)
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1 - 1; i >= 0; i--)
        {
            // starting backward from i = n1 - 1, would have to delete all chars from i to n1 to make it equal to empty string
            dp[i][n2] = dp[i + 1][n2] + s1[i];
        }
        for (int i = n2 - 1; i >= 0; i--)
        {
            // same reasoning as above
            dp[n1][i] = dp[n1][i + 1] + s2[i];
        }
        
        // start traversing backward from dp[n1 - 1][n2 - 1]. whenever s1[i] == s2[j], forward dp[i + 1][j + 1] to dp[i][j]
        // if s1[i] != s2[j], set the minimum of ("deleting a char cost" from s1 + dp[i + 1][j]) and ("deleting a char cost" from s2 + dp[i][j + 1]) 
        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j]) dp[i][j] = dp[i + 1][j + 1];
                else
                {
                    dp[i][j] = min(
                        s1[i] + dp[i + 1][j],
                        s2[j] + dp[i][j + 1]
                    );
                }
            }
        }
        return dp[0][0];
    }
};

