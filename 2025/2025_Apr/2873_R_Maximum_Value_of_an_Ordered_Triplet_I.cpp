class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        long long ans = 0;
        long long maxval = 0;
        long long maxdif = 0;

        for (int i : nums)
        {
            ans = max(ans, maxdif * i);          // updates the greatest value of 'maxdif' * current value
            maxdif = max(maxdif, maxval - i);    // keep track of max difference between 'maxval' and current value
            maxval = max(maxval, (long long)i);  // keep track of max value in nums
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/editorial
*/
