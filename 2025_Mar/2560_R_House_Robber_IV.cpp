// 2025 Mar 15

class Solution {
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int n = nums.size();    // number of houses
        int L = 1;              // lowest value in 'nums'
        int R = 0;              // highest value in 'nums'

        for (int i : nums)      // get highest value in 'nums'
        {
            if (R < i) R = i;
        }

        while (L < R)               // find the min value out of max capabilities with binary search
        {
            int M = (L + R) / 2;    // set the middle value between L and R
            int cnt = 0;            // number of values that are greater than 'M' to steal

            // check how many values that are greater than 'M' can steal
            // and not stealing adjacent houses
            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= M)
                {
                    i++;
                    cnt++;
                }
            }

            if (cnt >= k) R = M;    // if 'cnt' reaches k, decreases the range 
            else L = M + 1;         // else, increases the range 
        }

        return L;
    }
};

/*
solution reference
https://leetcode.com/problems/house-robber-iv/editorial
*/
