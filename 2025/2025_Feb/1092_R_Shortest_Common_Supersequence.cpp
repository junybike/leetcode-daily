// 2025 Feb 28

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int n1 = str1.length();
        int n2 = str2.length();

        // length of shortest common supersequence for first row characters of str1 and first col characters of str2
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        
        // Base case initialization
        for (int row = 0; row <= n1; row++)
        {
            dp[row][0] = row;
        }  
        for (int col = 0; col <= n2; col++)
        {
            dp[0][col] = col;
        }  

        // Filling DP table
        for (int row = 1; row <= n1; row++)
        {
            for (int col = 1; col <= n2; col++)
            {
                // If characters match, record new length by appending 1 from the diagonal
                // else, record the minimum length option and append 1.
                if (str1[row - 1] == str2[col - 1]) dp[row][col] = dp[row - 1][col - 1] + 1;
                else dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1; 
            }
        } 

        string sequence = "";
        int row = n1;
        int col = n2;

        while (row > 0 && col > 0)
        {
            // If characters match, populate it and move diagnoally in 'dp'
            if (str1[row - 1] == str2[col - 1])
            {
                sequence += str1[row - 1];
                row --;
                col --;
            }
            // else if, take the shorter sequence out of the left or up from the dp[row][col].
            else if (dp[row - 1][col] < dp[row][col - 1])
            {
                sequence += str1[row - 1];
                row--;
            }
            else
            {
                sequence += str2[col - 1];
                col--;
            }
        }

        // Appending the remaining characters from str1 or str2
        while (row > 0)
        {
            sequence += str1[row - 1];
            row--;
        }
        while (col > 0)
        {
            sequence += str2[col - 1];
            col--;
        }

        // Reverses the sequence since the string was formed with bottom-up approach
        reverse(sequence.begin(), sequence.end());
        return sequence;
    }
};
/*
solution reference
https://leetcode.com/problems/shortest-common-supersequence/editorial
*/
