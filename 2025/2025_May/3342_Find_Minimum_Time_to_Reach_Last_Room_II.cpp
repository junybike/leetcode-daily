// 2025 May 8
// Question 3341 shares the same comment

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};
        int numRow = moveTime.size();
        int numCol = moveTime[0].size();

        vector<vector<bool>> visited(numRow, vector<bool>(numCol, false));
        priority_queue<Cell> pq;

        pq.push(Cell(0, 0, 0, false));
        visited[0][0] = true;

        while (!pq.empty())
        {
            Cell cur = pq.top();
            pq.pop();

            int curRow = cur.row;
            int curCol = cur.col;
            int curCost = cur.cost;
            bool curFlag = cur.flag;
            
            if (curRow == numRow - 1 && curCol == numCol - 1) return curCost;

            for (int i = 0; i < 4; i++)
            {
                int adjRow = curRow + dRow[i];
                int adjCol = curCol + dCol[i];

                if (isValidCell(adjRow, adjCol, numRow, numCol) && !visited[adjRow][adjCol])
                {
                    int moveCost = 1;
                    if (curFlag) moveCost++;    // if moving from true flag, it took cost 1 for moving. next move must be cost 2 
                    
                    pq.push(Cell(max(cur.cost + moveCost, moveTime[adjRow][adjCol] + moveCost), adjRow, adjCol, !curFlag));
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
        bool flag;

        // Constructor to initialize a cell
        Cell(int cost, int row, int col, bool flag) : cost(cost), row(row), col(col), flag(flag) {}

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

