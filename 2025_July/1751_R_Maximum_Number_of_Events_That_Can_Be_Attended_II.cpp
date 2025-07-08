// 2025 July 8
class Solution {
public:

    // finding first event which the start time is after a target time 
    int search(vector<vector<int>>& events, int target) 
    {
        int L = 0;
        int R = events.size();

        while (L < R)
        {
            int M = (L + R) / 2;
            if (events[M][0] <= target) L = M + 1;
            else R = M;
        }
        return L;
    }

    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n = events.size();

        // dp[j][i] = max value achieved by attending j events starting from index i
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        sort(events.begin(), events.end());

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
            {
                // decide whether to attend the next event that start after this one ends or skip it
                int next = search(events, events[i][1]);
                dp[j][i] = max(dp[j][i + 1], events[i][2] + dp[j - 1][next]);
            }
        }
        return dp[k][0];
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/editorial
*/
