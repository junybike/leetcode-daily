// 2024 Nov 21

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        // The m x n grid with all 0 as default.
        int grid[m][n];
        memset(grid, 0, sizeof(grid));

        // On the grid, mark the one that is occupied by guards andw walls with 2
        for (auto& g : guards)
        {
            grid[g[0]][g[1]] = 2;
        }
        for (auto& w : walls)
        {
            grid[w[0]][w[1]] = 2;
        }

        // Direction indication array
        int dir[5] = {-1, 0, 1, 0, -1};

        for (auto& g: guards)
        {
            for (int i = 0; i < 4; i++)
            {
                int x = g[0];           // Current guard's x pos 
                int y = g[1];           // Current guard's y pos
                
                int dx = dir[i];        // Setting the direction (W, E)
                int dy = dir[i + 1];    // Setting the direction (N, S)

                // If going S, dx would be dir[1] and dy is dir[2]

                // Guards checking the cells from their position to N, E, S, W
                // up to the walls or other guards.
                while (x + dx >= 0 && x + dx < m &&
                        y + dy >= 0 && y + dy < n &&
                        grid[x + dx][y + dy] < 2)
                {
                    x += dx;            // Move with the direction (W, E)
                    y += dy;            // Move with the direction (N, S)
                    grid[x][y] = 1;     // Mark the cell as guarded if it is reached
                }
            }
        }

        // Count the number of unguarded cells.
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans += count(grid[i], grid[i] + n, 0);
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/count-unguarded-cells-in-the-grid/solutions/6067031/beats-100-video-full-explain-2-approaches
*/
