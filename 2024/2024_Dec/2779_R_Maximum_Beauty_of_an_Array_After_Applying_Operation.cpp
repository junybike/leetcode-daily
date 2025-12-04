// 2024 Dec 11

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int high = 0;       // To store the greatest value in 'nums'
        int low = 10e5;     // To store the least value in 'nums'

        // Find the least and greatest value in 'nums'
        for (int i : nums)
        {
            if (i > high) high = i;
            if (i < low) low = i;
        }

        int n = high - low;             // Number of possible different values in 'nums'
        vector<int> freq(n + 1, 0);     // To record the frequency for each possible values in 'nums'

        // For each values in 'nums' record their frequency.
        for (int i : nums)
        {
            freq[i - low]++;
        }

        int cnt = 0;    // To keep track of sum of all frequency of values that are in the range
        int ans = 0;    // To keep the greatest amount of iteration. The value to return. 

        // Sliding window
        for (int L = 0, R = 0; R <= n; R++)
        {
            cnt += freq[R];     // Sum up the Rth value's frequency

            // If the range is greater than 2 * k (must keep range from i - k to i + k), shrink the range by increasing 'L'
            if (R - L > 2 * k)
            {
                cnt -= freq[L]; // Subtract the frequency of Lth value as the range shrinks. 
                L++;            // Increase 'L'
            }

            // If the current count 'cnt' in greater than 'ans', update 'ans'.
            if (cnt > ans) ans = cnt;
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/solutions/6134245/freq-count-sliding-window-3ms-beats-99-70
*/
