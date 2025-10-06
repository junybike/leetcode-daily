// 2025 Oct 6
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;               // max time need to wait to reach to bottom right

        priority_queue<tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>> pq;  // stores location with least time value at the top

        pq.push(make_tuple(grid[0][0], 0, 0));

        while (!pq.empty())  
        {
            tuple<int,int,int> cur = pq.top();  // get the location with least time value
            pq.pop();

            int t = get<0>(cur);    // time value
            int y = get<1>(cur);    // row
            int x = get<2>(cur);    // col

            grid[y][x] = -1;                            // mark as visited
            if (time < t) time = t;                     // update max time need to wait
            if (x == n - 1 && y == m - 1) return time;  // return the time if this is the bottom right location

            // push adjacent locations
            if (x + 1 < n && grid[y][x + 1] != -1) pq.push(make_tuple(grid[y][x + 1], y, x + 1));
            if (x - 1 >= 0 && grid[y][x - 1] != -1) pq.push(make_tuple(grid[y][x - 1], y, x - 1));
            if (y + 1 < m && grid[y + 1][x] != -1) pq.push(make_tuple(grid[y + 1][x], y + 1, x));
            if (y - 1 >= 0 && grid[y - 1][x] != -1) pq.push(make_tuple(grid[y - 1][x], y - 1, x));
        }

        return -1;
    }
};
