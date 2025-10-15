// 2025 Oct 15
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        int L = 0;

        vector<int> sub(n, 1);              // stores length of increasing sequence ending at i
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                sub[i] = sub[i - 1] + 1;
            }
        }  

        vector<int> subStart(n, 1);         // stores length of increasing sequence starting from i
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                subStart[i] = subStart[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)     // find the max length of increasing sequences adjacent to others
        {   
            int cur = min(sub[i], subStart[i + 1]); 
            ans = max(ans, cur);
        }

        return ans;    
    }
};
