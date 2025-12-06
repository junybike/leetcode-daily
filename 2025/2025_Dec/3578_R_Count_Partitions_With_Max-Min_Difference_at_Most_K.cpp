// 2025 Dec 6
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        vector<long long> dp(n + 1);        // dp[i + 1] = number of valid partitions for nums[0..i]
        vector<long long> prefix(n + 1);    // prefix[i + 1] = sum of dp[j] from 0 <= j <= i
        multiset<int> cnt;                  // contains current partition's values 

        dp[0] = 1;
        prefix[0] = 1;  
    
        for (int i = 0, j = 0; i < n; i++)
        {
            cnt.emplace(nums[i]);   // store each value in nums in cnt

            // if the max - min in cnt exceeds k, take out nums[j] until j reaches i or the difference is below k
            while (j <= i && *cnt.rbegin() - *cnt.begin() > k)
            {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }

            // update dp and prefix
            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + MOD) % MOD;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD; 
        }
        return dp[n];
    }
};
/*
solution reference
https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/editorial
*/
