// 2025 Mar 6

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();        // squre root(size of grid) 
        vector<int> freq(n * n, 0); // records if certain value is present or not 
        vector<int> ans(2, 0);      // to return the value that appears more than once and the value that does not appear 

        for (auto& v : grid)
        {
            for (int i : v)
            {
                freq[i - 1]++;                      // record the present values
                if (freq[i - 1] > 1) ans[0] = i;    // check if this value appears more than once
            }
        }
        for (int i = 0; i < n * n; i++)             // find the value that doesnt appear in 'grid'
        {
            if (!freq[i]) ans[1] = i + 1;
        }

        return ans;
    }
};
