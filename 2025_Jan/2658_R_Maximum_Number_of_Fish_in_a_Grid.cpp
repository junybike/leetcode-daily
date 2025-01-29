// 2025 Jan 28

class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col)
    {
        // Check if the location (row, col) is within the range of grid
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col])
        {
            return 0;
        }
        // Set this location as visited
        visited[row][col] = true;

        // perform DFS to add all adjacent grid's fishes 
        return grid[row][col] + 
                dfs(grid, visited, row, col + 1) +
                dfs(grid, visited, row, col - 1) +
                dfs(grid, visited, row + 1, col) +
                dfs(grid, visited, row - 1, col);
    }

    int findMaxFish(vector<vector<int>>& grid) 
    {
        int row = grid.size();    // row size of the grid
        int col = grid[0].size(); // col size of the grid
        
        int maxfish = 0;  // maximum number of fish found at a location + all its adj water grids
        vector<vector<bool>> visited(row, vector<bool>(col, false));  // Record each grids if they are visited or not
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!grid[i][j]) continue;                        // If the grid is land, skip.
                maxfish = max(maxfish, dfs(grid, visited, i, j)); // If the grid is water, compute sum of all fishes from its adjacent grids
                                                                  // update the maxfish value if the sum is greater than the maxfish.
            }
        }    
        return maxfish;
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/editorial
*/

/*
solution reference
https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/editorial
*/
