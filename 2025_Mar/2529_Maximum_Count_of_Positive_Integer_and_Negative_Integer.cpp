class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int neg = 0;
        int pos = 0;

        for (int i : nums)
        {
            if (i < 0) neg++;        // count the value less than 0
            else if (i > 0) pos++;   // count the value greater than 0
        }    

        if (neg > pos) return neg;
        else return pos;
    }
};

// Log(N)
class Solution {
public:

    // Finds the first non zero positive value in 'nums'
    int upperBound(vector<int>& nums)
    {
        int L = 0;
        int R = nums.size() - 1;
        int index = nums.size();

        while (L <= R)
        {
            int M = (L + R) / 2;
            if (nums[M] <= 0) L = M + 1;
            else if (nums[M] > 0)
            {
                R = M - 1;
                index = M;
            }
        }
        return index;
    }

    // Finds the first zero value in 'nums'
    int lowerBound(vector<int>& nums)
    {
        int L = 0;
        int R = nums.size() - 1;
        int index = nums.size();

        while (L <= R)
        {
            int M = (L + R) / 2;
            if (nums[M] < 0) L = M + 1;
            else if (nums[M] >= 0)
            {
                R = M - 1;
                index = M;
            }
        }
        return index;
    }

    int maximumCount(vector<int>& nums) 
    {
        int pos = nums.size() - upperBound(nums);
        int neg = lowerBound(nums);
        return max(pos, neg);
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/editorial
*/
