// 2024 Oct 27

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();      // The height of matrix
        int m = matrix[0].size();   // The width of matrix
        int ans = 0;                // The number of squares

        // DP table
        vector<vector<int>> dp(n, vector<int>(m, 0));   

        // Filling the first column and first row of DP table.
        // Also a case where matrix[i][0] = 1 indicates a 1 x 1 square. 
        for (int i = 0; i < n; i++) // first column
        {
            dp[i][0] = matrix[i][0];    // Assign dp[i][0] a value 1 if there is a sqare. Else, 0.
            ans += dp[i][0];            // Increment square count to ans.
        }
        for (int i = 1; i < m; i++) // first row
        {
            dp[0][i] = matrix[0][i];    // Assign dp[0][i] a value 1 if there is a square. Else, 0. 
            ans += dp[0][i];            // Increment square count to ans;
        }

        // Filling the remaining cells of DP table
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                // Case where a cell has the value 1.
                if (matrix[i][j] == 1)
                {
                    // Assign dp[i][j] a minimum value of 
                    //  - its left cell
                    //  - its top cell
                    //  - its top left diagonal cell
                    // If one of the value is 0, this cell won't contain a perfect square.
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
                ans += dp[i][j];    // Updating the count of squares 
            }
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/5972616/explained-step-by-step-beats-100-working-27-10-2024
*/
