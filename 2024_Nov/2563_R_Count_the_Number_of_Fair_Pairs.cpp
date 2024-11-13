// 2024 Nov 13

class Solution {
public:

    long long countnums(vector<int>& nums, int range)
    {
        long long ans = 0;

        for (int i = 0, j = nums.size() - 1; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > range) j--;
            ans += j - i;
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(), nums.end());
        return countnums(nums, upper) - countnums(nums, lower - 1);
    }
};

/*
Solution reference
https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/6038987/1-ms-beats-100
*/
