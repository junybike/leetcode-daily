// 2025 Jan 22

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int dRow[4] = {0, 0, -1, 1};   
        int dCol[4] = {-1, 1, 0, 0};

        int n = isWater.size();     // Number of rows in 'isWater'
        int m = isWater[0].size();  // Number of columns in 'isWater'

        priority_queue<Cell> pq;                            // To store new grids which their adjacent grids have to be checked
        vector<vector<int>> peaks(n, vector<int> (m, -1));  // To record the height of each grids

        // Find all grids with waters first and push it to 'pq' and record in 'peaks'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j]) 
                {
                    pq.push(Cell(0, i, j));
                    peaks[i][j] = 0;
                }
            }
        }

        while (!pq.empty())
        {
            Cell cur = pq.top();    // Get current grid with lowest height
            pq.pop();               

            // current grid's location and height
            int curRow = cur.row;           
            int curCol = cur.col;
            int curHeight = cur.height;

            // Check all possible adjacent grids from the current grid 
            for (int i = 0; i < 4; i++)
            {
                // The adjacent grid's location
                int adjRow = curRow + dRow[i];
                int adjCol = curCol + dCol[i];

                // Check if the adjacent grid is within the range and has not visited yet.
                if (isValidCell(adjRow, adjCol, n, m) && peaks[adjRow][adjCol] == -1)
                {
                    peaks[adjRow][adjCol] = curHeight + 1;          // Record the adjacent grid's height as the current + 1
                    pq.push(Cell(curHeight + 1, adjRow, adjCol));   // Push the adjacent grid to the 'pq'
                }
            }
        }
        return peaks;
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
    };

    // Helper function to check if a cell is valid (within grid bounds)
    bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};
