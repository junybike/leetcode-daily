// 2024 Dec 13

class Solution {
public:

    long long findScore(vector<int>& nums) 
    {
        int n = nums.size();                                // The size of 'nums'
        vector<vector<int>> info(n, vector<int>(2, 0));     // Stores values and its index in 'nums'
        vector<int> marked(n, 0);                           // Stores the indexes that are marked

        // Initialize the 'info' vector
        for (int i = 0; i < n; i++)
        {
            info[i][0] = nums[i];
            info[i][1] = i;
        }
        sort(info.begin(), info.end()); // Sort the info vector in ascending order of the values.

        long long score = 0;    // The sum of scores to return

        for (auto& arr : info)
        {
            int v = arr[0]; // The value
            int i = arr[1]; // Value's index

            if (marked[i] > 0) continue;    // If current value's index is marked, skip.
            else score += v;                // Else, sum up its value to score

            // Mark the index's neighbor if they are within the range of 'n'.
            if (i - 1 >= 0 && i - 1 < n) marked[i - 1]++;   
            if (i + 1 >= 0 && i + 1 < n) marked[i + 1]++;
        }
        return score;
    }
};
