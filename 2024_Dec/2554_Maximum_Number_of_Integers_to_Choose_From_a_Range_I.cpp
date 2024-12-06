// 2024 Dec 6

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        int sum = 0;                    // To track of total sum  
        int ans = 0;                    // To track of total number of sum made
        unordered_map<int, int> umap;   // To store all values in 'banned'

        // Store all values in 'banned' to 'umap'
        for (int i : banned) umap[i] = 1;

        for (int i = 1; i <= n; i++)
        {
            // If sum + i exceeds maxSum, end the loop. 
            // There are no more numbers to be added while not exceeding maxSum.
            if (sum + i > maxSum) break;

            // If the current number 'i' is not in 'umap', number is not banned.
            // Add 'i' to sum and increment 'ans'
            if (umap[i] != 1)
            {
                sum += i;
                ans++;
            }
        }
        return ans;
    }
};
