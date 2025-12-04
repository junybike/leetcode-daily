// 2025 May 7

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        // direction array for checking adjacent cells
        int dRow[4] = {0, 0, -1, 1};        
        int dCol[4] = {-1, 1, 0, 0};

        // number of row and col of moveTime
        int numRow = moveTime.size();
        int numCol = moveTime[0].size();

        // keep track of visited cells
        vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));

        // priority queue for BFS
        priority_queue<Cell> pq;

        // for starting point
        pq.push(Cell(0, 0, 0));
        visited[0][0] = true;

        while (!pq.empty())
        {
            Cell cur = pq.top();    // fetch the next shortest cell with least cost 
            pq.pop();               

            int curRow = cur.row;
            int curCol = cur.col;
            int curCost = cur.cost;
            
            // if arrived to the destination, return the cost
            if (curRow == numRow - 1 && curCol == numCol - 1) return curCost;

            for (int i = 0; i < 4; i++)
            {
                // the adjacent cell location
                int adjRow = curRow + dRow[i];  
                int adjCol = curCol + dCol[i];

                // check if the adjacent cell is within the grid and not visited yet
                if (isValidCell(adjRow, adjCol, numRow, numCol) && !visited[adjRow][adjCol])
                {
                    // push the adjacent node to the pq and mark it as visited
                    // the cost is set to be the larger one out of the current cell's cost + 1 or the adjacent node's moveTime + 1
                    // this is because we are moving from the current cell. 
                    // if current cell has larger cost (time) recorded, we are moving from that time.
                    // if current cell has lower cost (time) recorded, we have to wait for the moveTime of the adjacent cell.
                    // extra +1 for each cost is for moving time
                    pq.push(Cell(max(cur.cost + 1, moveTime[adjRow][adjCol] + 1), adjRow, adjCol));
                    visited[adjRow][adjCol] = true;
                }
            } 
        }
        return -1;
    }

private:
    // Struct to store the height and coordinates of a cell in the grid
    class Cell 
    {
    public:
        int cost;
        int row;
        int col;

        // Constructor to initialize a cell
        Cell(int cost, int row, int col) : cost(cost), row(row), col(col) {}

        // Overload the comparison operator to make the priority queue a
        // min-heap based on height
        bool operator<(const Cell& other) const 
        {
            // Reverse comparison to simulate a min-heap
            return cost >= other.cost;
        }
    };

    // Helper function to check if a cell is valid (within grid bounds)
    bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};
