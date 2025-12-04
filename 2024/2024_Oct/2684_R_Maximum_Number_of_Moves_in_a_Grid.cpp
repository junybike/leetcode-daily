// 2024 Oct 29

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        int n = grid.size();        // The number of rows
        int m = grid[0].size();     // The number of cols
        int ans = 0;

        // Table to record each grid's "value"
        vector<vector<int>> table(n, vector<int>(m, 0));  

        for (int i = n - 1; i > 0; i--)
        {
            for (int j = m - 1; j > 0; j--)
            {
                // If there is a following grid with value strictly smaller than the current grid, increments the current grid's value by one.
                // - a grid on the left (row, col - 1)
                // - a grid on the upward left (row + 1, col - 1)
                // - a grid on the downward left (row - 1, col - 1)
                if (grid[i][j] > grid[i][j - 1]) table[i][j - 1] = table[i][j] + 1; 
                if (grid[i][j] > grid[i - 1][j - 1]) table[i - 1][j - 1] = table[i][j] + 1;
                if (i != n - 1 && grid[i][j] > grid[i + 1][j - 1]) table[i + 1][j - 1] = table[i][j] + 1;
            }
        }

        // Find the grid with greatest value on the leftmost columns on any row 
        for (int i = 0; i < n; i++)
        {
            if (table[i][0] > ans) ans = table[i][0]; 
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/solutions/5980491/beats-61-54-step-by-step-breakdown
*/
