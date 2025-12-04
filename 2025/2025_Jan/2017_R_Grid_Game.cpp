// 2025 Jan 21

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) 
    { 
        int n = grid[0].size();         // The length of the grid
        long long ans = LONG_LONG_MAX;  // To record the second robot's score

        long long top = 0;  // Sum of points in the top row
        long long bot = 0;  // Sum of points in the bottom row

        // Pre-calculate all points in the top row
        for (int i = 0; i < n; i++)
        {
            top += grid[0][i];
        }

        // Starting from the top row, first robot moves right.
        for (int i = 0; i < n; i++)
        {
            top -= grid[0][i];              // As it moves to right, 'top' gets decrements by the point at current grid.
            ans = min(ans, max(top, bot));  // The max point if second robot gets down at the current grid
            bot += grid[1][i];              // Adds the bottom point to 'bot' 
        }

        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/grid-game/solutions/6295086/grid-game
*/
