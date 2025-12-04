// 2024 Oct 30

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();    // The size of vector 'nums'
        if (n == 3) return 0;   // If size is 3, the vector 'nums' is already a mountain array

        vector<int> Llis(n, 1); // The longest increasing subseqeunce starting from left side of 'nums'
        vector<int> Rlis(n, 1); // The longest increasing subsequence starting form right side of 'nums'

        // Setting up Llis
        for (int i = 1; i < n; i++) 
        {
            for (int prev = 0; prev < i; prev++) 
            {
                if (nums[i] > nums[prev] && Llis[i] < Llis[prev] + 1) Llis[i] = Llis[prev] + 1;
            }
        }

        // Setting up Rlis
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] > nums[j]) Rlis[i] = max(Rlis[i], Rlis[j] + 1);
            }
        }

        // Finding the mountain with largest area from an overall mountain (Llis + Rlis)
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (Llis[i] != 1 && Rlis[i] != 1) ans = max(ans, Llis[i] + Rlis[i]);
        }

        // Size of 'nums' - largest mountain length gives the total amount of values need to be deleted 
        return n - ans + 1;
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/solutions/5984651/a-throught-way-of-tackling-this-problem
*/
