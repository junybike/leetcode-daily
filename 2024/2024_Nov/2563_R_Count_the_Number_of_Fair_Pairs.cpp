// 2024 Nov 13

class Solution {
public:

    long long countnums(vector<int>& nums, int range)
    {
        long long ans = 0;

        // Determine the maximum number of pairs for each value and add the number to 'ans' 
        for (int i = 0, j = nums.size() - 1; i < j; i++)
        {
            // For the current value from the 'nums' vector, check by forming a pair with the greatest value in the vector.
            // Continue checking with the second greatest value and so on.
            // Decrease the range of 'nums' vector (j) when the sum of a pair exceeds the range. 
            while (i < j && nums[i] + nums[j] > range) j--;

            // Once they find an eligible pair, record and add the boundary of the vector.
            ans += j - i;
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        // Sort the 'nums' vector to make the iteration optimal.
        // As the value gets larger, the boundary for lower and upper gets narrower for values in 'nums'
        sort(nums.begin(), nums.end());

        // Calculate the possible number of pairs whose sums are less or equal to the upper and subtract 
        // possible number of pairs whose sums are less or equal to the lower.
        return countnums(nums, upper) - countnums(nums, lower - 1);
    }
};

/*
Solution reference
https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/6038987/1-ms-beats-100
*/
