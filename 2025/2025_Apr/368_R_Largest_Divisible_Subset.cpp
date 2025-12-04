// 2025 Apr 6

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end()); // sort 'nums' in increasing order
        int n = nums.size();            // size of 'nums'

        // for ith value, keep track of how many values in 0 to i-1 index in 'nums' can be divisible
        vector<int> dp(n, 1);       

        // for ith value, keep track of the last previous value at index that can divide the value in ith index in 'nums'     
        vector<int> prev(n, -1);     

        int max_cnt = 0;            // track of the max amount of divisible for a subset
        for (int i = 1; i < n; i++) // initialize dp
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_cnt]) max_cnt = i;   // update max_cnt as initializing dp
        }    

        vector<int> ans;    // to return the subset

        // from the max_cnt index, append all values by following the index in prev
        for (int i = max_cnt; i >= 0; i = prev[i]) 
        {
            ans.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/largest-divisible-subset/solutions/6620153/dp-sorting-with-images-example-walkthrough-c-python-java
*/
