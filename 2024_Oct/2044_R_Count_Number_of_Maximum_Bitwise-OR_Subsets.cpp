class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        int maxvalue = 0; 
        int ans = 0;

        // Get the maximum Bitwise-OR from 'nums'
        for (int x : nums) 
        {
            maxvalue |= x;
        }
    
        int t = 1 << n; // t = 2^n
        for (int i = 1; i < t; i++) // for all possible 2^n subsets
        {
            // Tries to match 'temp' to the 'maxvalue' with Bitwise ORing the subset of values in 'nums'
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                // When i & 2^j is not zero, assign bitwise or with 'temp' and current value at 'nums'
                if (i & (1 << j)) temp = temp | nums[j];
            }

            // Increment 'ans' when the 'temp' reaches the 'maxvalue' 
            if (temp == maxvalue) ans++;
        }
        
        return ans;
    }
};

/*
Solution reference
https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/solutions/5928791/straight-forward-approach-easy-to-understand-c
*/
