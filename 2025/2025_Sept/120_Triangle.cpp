// 2025 Sept 25
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++) // sum up each values in this row with the lowest "adjacent" values in previous row   
            {
                if (j == 0) triangle[i][0] += triangle[i - 1][0];                       
                else if (i == j) triangle[i][i] += triangle[i - 1][i - 1];
                else triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        } 

        int ans = INT_MAX;
        for (int i : triangle[n - 1])   // find the lowest sum at the last row
        {
            ans = min(i, ans);
        }
        return ans;
    }
};
