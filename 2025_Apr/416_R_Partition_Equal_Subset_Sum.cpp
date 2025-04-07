// 2025 Apr 7
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int total = 0;      // The total sum of values in 'nums'
        for (int i : nums)
        {
            total += i;
        }
        if (total % 2 != 0) return false;   // if the total is not even, cant partition equal two subset sum

        int target = total / 2;             // the halve of total (each subset's total sum)
        vector<bool> dp(target + 1, false); // dp[i] stores true if sum i by the subset is possible
        dp[0] = true;

        for (int i : nums)
        {
            for (int cur = target; cur >= i; cur--)
            {
                dp[cur] = dp[cur] || dp[cur - i];   // determine if getting subset sum of i is possible including the current number 
                if (dp[target]) return true;        // sum i is possible by the subset
            }
        }
        return dp[target];

    }
};
/*
solution reference
https://leetcode.com/problems/partition-equal-subset-sum/solutions/6623686/0-1-knapsack-dp-with-images-example-walkthrough-c-python-java
*/
