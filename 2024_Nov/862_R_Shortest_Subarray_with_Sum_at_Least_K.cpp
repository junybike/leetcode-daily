// 2024 Nov 16

// My dynamic programming attmept. 

class Solution_MLE {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if (n == 1 && nums[0] >= k) return 1;
        else if (n == 1) return -1;

        vector<vector<int>> dp(n , vector<int> (n));
        int ans = INT_MAX;
        int total = 0;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
            if (nums[i] >= k) return 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            for (int j = i + 1; j < n; j++)
            {
                dp[l][j] = dp[l][j - 1] + dp[j][j];
                if (dp[l][j] >= k && j - l + 1 < ans) 
                {
                    cout << j - l + 1<< endl;
                    ans = j - l + 1;
                }
                l++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();            // the size of 'nums'
        vector<long long> sum(n + 1);   // stores the cumulative sum as it iterates 'num'

        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }    

        vector<int> arr(n + 1); // Monotonic queue. Stores the 
        int L = 0;              // A pointer on the left side of 'arr'
        int R = 0;              // A pointer on the right side of 'arr' (L < R)
        int ans = n + 1;        // The smallest number of values in 'nums' that can be added and be greater or equal to k


        // Perform sliding window
        for (int i = 0; i < n + 1; i++)
        {
            // While the cumulative sum upto index i of nums is greater or equal to the sum upto index arr[L] + k,
            // then k can be formed with i - arr[L] number of values in 'nums'.
            // If this number is lower than the current lowest (ans), update ans. However, increment 'L' regardless. 

            while (L < R && sum[i] >= sum[arr[L]] + k)
            {
                ans = min(ans, i - arr[L++]);
            }
            
            // If the cumulative sum upto arr[R - 1] index is greater or equal to the sum upto current index,
            // shrink the range by decrementing 'R'.

            while (L < R && sum[i] <= sum[arr[R - 1]])
            {
                cout << sum[i] << " ? <= " << sum[arr[R - 1]] << " R: " << R << endl;
                R--;
            }

            arr[R++] = i;   // Stores the current index at R and set R to R + 1. 
        }

        return ans <= n ? ans : -1;
    }
};

/*
solution reference
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/6052938/beats-100-sliding-windows-monotonic-queue
*/
