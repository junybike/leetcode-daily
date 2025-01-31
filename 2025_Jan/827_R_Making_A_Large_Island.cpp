// 2025 Jan 31

class Solution {
private:

    // To find an island size 
    int dfs(vector<vector<int>>& grid, int id, int row, int col)
    {
        // Check if the location at (row, col) is an unvisited (not group assigned) land and in the grid's range  
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1) return 0;
        grid[row][col] = id;    // assign this location an island group: 'id'

        // Check adjacent locations
        return 1 +
            dfs(grid, id, row + 1, col) +
            dfs(grid, id, row - 1, col) +
            dfs(grid, id, row, col + 1) +
            dfs(grid, id, row, col - 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        unordered_map<int, int> landSizes;  // Records island sizes
        int landID = 2;                     // island group id: it will assign each lands in 'grid'

        int rowSize = grid.size();      // row size of 'grid'
        int colSize = grid[0].size();   // column size of 'grid'

        // Finding all islands and their sizes
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (grid[i][j] == 1)
                {
                    landSizes[landID] = dfs(grid, landID, i, j);
                    landID++;
                }
            }
        }

        if (landSizes.empty()) return 1;    // case of no islands
        if (landSizes.size() == 1)          // case of one island
        {
            --landID;
            return (landSizes[landID] == rowSize * colSize) ? landSizes[landID] : landSizes[landID] + 1;
        }

        int maxSize = 1;    // to record the greates island size

        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                // For each grid with value '0'
                if (grid[row][col] == 0)
                {
                    int curSize = 1;                // current island size
                    unordered_set<int> adjLands;    // record adjacent island id of current location

                    // Search if adjacent location has been assigned an island group id. 
                    // If it is assigned, store that island group id's size to 'adjLands'
                    if (row + 1 < rowSize && grid[row + 1][col] > 1)
                    {
                        adjLands.insert(grid[row + 1][col]);
                    }
                    if (row - 1 >= 0 && grid[row - 1][col] > 1)
                    {
                        adjLands.insert(grid[row - 1][col]);
                    }
                    if (col + 1 < colSize && grid[row][col + 1] > 1)
                    {
                        adjLands.insert(grid[row][col + 1]);
                    }
                    if (col - 1 >= 0 && grid[row][col - 1] > 1)
                    {
                        adjLands.insert(grid[row][col - 1]);
                    } 

                    // Add up all sizes of islands stored in 'adjLands'
                    for (int i : adjLands)
                    {
                        curSize += landSizes[i];
                    }

                    // Update the max size of islands
                    maxSize = max(maxSize, curSize);
                }
            }
        }
        return maxSize;
    }
};
/*
solution
https://leetcode.com/problems/making-a-large-island/editorial
*/
