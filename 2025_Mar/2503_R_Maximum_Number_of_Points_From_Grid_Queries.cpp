// 2025 Mar 29

class Solution {
public:

    int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        int n = queries.size();     // size of 'queries'
        vector<int> ans(n);         // stores max points from each values in 'queries'

        int row = grid.size();                  
        int col = grid[0].size();

        // to store minimum query value required to reach i cells
        vector<int> maxpoint(row * col + 1);    
        
        // to store max value encountered to reach (i, j)
        vector<vector<int>> minvalue(row, vector<int>(col, INT_MAX));
        minvalue[0][0] = grid[0][0];
        
        // stores each (i, j) with its value in increasing order of encountered values
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        
        int visited = 0;
        while(!minHeap.empty())
        {
            array<int, 3> current = minHeap.top();  // current cell
            minHeap.pop();
            maxpoint[++visited] = current[0];   // the value required to reach ith visited cells

            for (auto& dir : DIR)   // check each adjacent cells
            {
                int newrow = current[1] + dir[0];
                int newcol = current[2] + dir[1];

                // if the adjacent cell is within range and not visited
                if (newrow >= 0 && newrow < row && newcol >= 0 && newcol < col && minvalue[newrow][newcol] == INT_MAX)
                {
                    // store max value required to reach to this cell and push to the heap to check its adj cells
                    minvalue[newrow][newcol] = max(current[0], grid[newrow][newcol]);
                    minHeap.push({minvalue[newrow][newcol], newrow, newcol});
                }
            }
        }   

        // for each query, find max number of points can be collected for each query
        for (int i = 0; i < n; i++)
        {
            int lim = queries[i];
            int L = 0;
            int R = row * col;

            // find rightmost number of points can be collected without exceeding lim
            while (L < R)   
            {
                int M = (L + R + 1) / 2;
                if (maxpoint[M] < lim) L = M;
                else R = M - 1;
            }
            ans[i] = L;
        } 
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/editorial
*/
