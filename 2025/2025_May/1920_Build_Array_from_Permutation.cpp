// 2025 May 6
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int> ans = nums;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // This way, the original value can still be accessed from nums
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        for (int& i : nums)
        {
            i /= 1000;
        }
        return nums;
    }
};
/*
https://leetcode.com/problems/build-array-from-permutation/editorial
*/
