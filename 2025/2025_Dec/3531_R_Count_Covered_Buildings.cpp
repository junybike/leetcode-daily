// 2025 Dec 11
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
    {
        vector<int> maxRow(n + 1);          // maxRow[i] = the furthest from row 0 at x = i
        vector<int> minRow(n + 1, n + 1);   // minRow[i] = the closest from row 0 at x = i 
        vector<int> maxCol(n + 1);          // maxCol[i] = the furthest from col 0 at y = i
        vector<int> minCol(n + 1, n + 1);   // minCol[i] = the closets from col 0 at y = i

        for (auto& p : buildings)
        {
            int x = p[0];
            int y = p[1];

            // By iterating each building, update the min/max row/col
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }    

        int ans = 0;
        for (auto& p : buildings)
        {
            int x = p[0];
            int y = p[1];

            // Check each building if they are between some buildings at its row and col
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x] && y < maxCol[x]) ans++;
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/count-covered-buildings/editorial
*/
