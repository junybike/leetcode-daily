// 2025 June 29
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        int MOD = 1000000007;
        int n = nums.size();
        
        vector<int> power(n, 0);
        power[0] = 1;
        for (int i = 1; i < n; i++)
        {
            power[i] = (power[i - 1] * 2) % MOD;    // number of valid subsequences in any window
        }    

        int L = 0;      // min value of subsequence
        int R = n - 1;  // max value of subsequence
        int ans = 0;

        while (L <= R)
        {
            if (nums[L] + nums[R] <= target)    // check if this subsequence is valid
            {
                ans = (ans + power[R - L]) % MOD;
                L++;
            }
            else R--;
        }
        return ans;
    }
};
/*
solution
https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/6896464/beginner-freindly-java-c-python-js
*/
