// 2025 July 30
class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int val = 0;    // greatest value in nums
        for (int i : nums)
        {
            if (i > val) val = i;
        }

        int cnt = 0;    // to search for length of longest subarray
        int ans = 0;    // keep track of length of longest subarray

        for (int i : nums)
        {
            if ((val & i) == val) cnt++;
            else 
            {
                ans = max(cnt, ans);
                cnt = 0;
            }
        }

        return max(cnt, ans);    
    }
};
