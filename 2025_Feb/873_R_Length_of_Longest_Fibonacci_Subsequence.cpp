// 2025 Feb 27

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int len = 0;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));   // stores length of Fibonacci sequence ending at indexes prev and cur
        unordered_map<int, int> umap;                   // value -> index
        
        for (int cur = 0; cur < n; cur++)
        {
            umap[arr[cur]] = cur;   // initializing 'umap'

            for (int prev = 0; prev < cur; prev++)  // checking all values before 'cur'
            {
                int diff = arr[cur] - arr[prev];    // the difference between cur and prev
                int prevIndex = -1;                 // placeholder for prev's index if it exists in 'umap'

                // In case where 'diff' exists: record the potentially greater Fibonacci length
                // If doesnt exists, record it as 2  
                if (umap.find(diff) != umap.end()) prevIndex = umap[diff]; 
                if (diff < arr[prev] && prevIndex >= 0) dp[prev][cur] = dp[prevIndex][prev] + 1;
                else dp[prev][cur] = 2;

                // If the new length is greater than 'len' update the 'len'.
                if (len < dp[prev][cur]) len = dp[prev][cur];
            }
        }

        if (len > 2) return len;
        else return 0;              // Fibonacci sequence does not exists
    }
};

/*
solution reference
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/editorial
*/
