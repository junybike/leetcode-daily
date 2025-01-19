// 2025 Jan 19

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};
        int numRow = heightMap.size();
        int numCol = heightMap[0].size();

        // To record if the current grid is visited
        vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
        // To process grid in increasing height order
        priority_queue<Cell> pq;    

        // Visit the left and right edge grids
        for (int i = 0; i < numRow; i++)
        {
            pq.push(Cell(heightMap[i][0], i, 0));
            pq.push(Cell(heightMap[i][numCol - 1], i, numCol - 1));
            visited[i][0] = visited[i][numCol - 1] = true;
        }

        // Visit thee top and bottom edge grids
        for (int i = 0; i < numCol; i++)
        {
            pq.push(Cell(heightMap[0][i], 0, i));
            pq.push(Cell(heightMap[numRow - 1][i], numRow - 1, i));
            visited[0][i] = visited[numRow - 1][i] = true;
        }

        int water = 0;  // total water volume

        while (!pq.empty())
        {
            Cell cur = pq.top();    // Get the grid with the lowest height
            pq.pop();

            // Current grid's location and height
            int curRow = cur.row;           
            int curCol = cur.col;
            int minHeight = cur.height;

            // Process adjacent grids of the current grids
            for (int i = 0; i < 4; i++)
            {
                // The adjacent grid's location
                int adjRow = curRow + dRow[i];
                int adjCol = curCol + dCol[i];

                // Check if the adjacent grid is within the range and has not visited yet.
                if (isValidCell(adjRow, adjCol, numRow, numCol) && !visited[adjRow][adjCol])
                {
                    int adjHeight = heightMap[adjRow][adjCol];  // Height of the adjacent grid

                    // Record the water volume if the adjacent grid's height is lower than the current grid
                    if (adjHeight < minHeight) water += minHeight - adjHeight;  

                    // Record the adjacent grid to the 'pq' and mark this grid as visisted.
                    pq.push(Cell(max(adjHeight, minHeight), adjRow, adjCol));
                    visited[adjRow][adjCol] = true;
                }
            }
        }
        return water;
    }

private:
    // Struct to store the height and coordinates of a cell in the grid
    class Cell 
    {
    public:
        int height;
        int row;
        int col;

        // Constructor to initialize a cell
        Cell(int height, int row, int col) : height(height), row(row), col(col) {}

        // Overload the comparison operator to make the priority queue a
        // min-heap based on height
        bool operator<(const Cell& other) const 
        {
            // Reverse comparison to simulate a min-heap
            return height >= other.height;
        }
    };

    // Helper function to check if a cell is valid (within grid bounds)
    bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};
/*
solution reference
https://leetcode.com/problems/trapping-rain-water-ii/solutions/6293230/trapping-rain-water-ii
*/
