// 2025 Aug 1
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans(numRows, vector<int>(1, 1));
        if (numRows == 1) return ans;

        ans[1] = {1, 1};
        for (int i = 2; i < numRows; i++)
        {
            vector<int> cur(i + 1, 1);  // set up a vector for each row filled with 1
            ans[i] = cur;

            for (int j = 1; j < i; j++) // the addition for the row
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        return ans;    
    }
};
