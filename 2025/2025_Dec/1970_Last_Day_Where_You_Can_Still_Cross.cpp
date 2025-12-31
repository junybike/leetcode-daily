// 2025 Dec 31
class Solution {
public:

    int row;
    int col;
    vector<vector<int>> cells;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0)); // represents land. grid[i][j] = 0 is land and 1 is water.

        for (int i = 0; i < day; i++)   // fill the water at ith day.
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;    // for BFS. keep the starting positions and reachable positions
        vector<vector<bool>> visited(row, vector<bool>(col, false));    // keep track of visited positions

        for (int i = 0; i < col; i++)   // push available starting positions to q
        {
            if (grid[0][i] == 0)
            {
                q.push({0, i});
                visited[0][i] = true;
            }
        }

        while (!q.empty())  // perform BFS
        {
            auto [x, y] = q.front();
            q.pop();
            
            if (x == row - 1) return true;  // reached to bottom. return true.
            for (auto& d : dirs)            // try travel left right bottom up from current position.
            {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && grid[nx][ny] == 0) 
                {
                    visited[nx][ny] = true; // mark as visited and push the position to q since it is reachable
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int r, int c, vector<vector<int>>& cells_) 
    {
        row = r;
        col = c;
        cells = cells_;

        int left = 0;           // the first day 
        int right = row * col;  // the last day
        int ans = 0;

        // to perform binary search on days to find last day where you can still cross
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canCross(mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};

// Answer supported by chatgpt
