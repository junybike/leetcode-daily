// 2025 Mar 5

class Solution {
public:
    long long coloredCells(int n) 
    {
        long long area = 1;          // The number of colored cells
        for (int i = 1; i < n; i++)
        {
            area += 4 * i;           // Each iteration, 4 * i cells are colored
        }
        return area;
    }
};
