// 2025 Oct 14
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        if (k == 1) return true;

        int n = nums.size();
        int L = 0;

        vector<int> sub(n, 1);            // stores length of increasing sequence ending at i
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                sub[i] = sub[i - 1] + 1;
            }
        }  

        vector<int> subStart(n, 1);        // stores length of increasing sequence starting from i
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                subStart[i] = subStart[i + 1] + 1;
            }
        }

        for (int i = 0; i < n - 1; i++)    // find if the length of two adjacent increasing subarrays is at least k 
        {
            if (sub[i] >= k && subStart[i + 1] >= k) return true;
        }

        return false;
    }
};
