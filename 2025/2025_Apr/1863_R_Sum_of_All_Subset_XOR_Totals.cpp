// 2025 Apr 5

class Solution {
public:
    int subsetXORSum(vector<int>& nums) 
    {
        int ans = 0;
        for (int i : nums)
        {
            ans |= i;   // Any bit that is set in any of other elements
        }
        return ans << (nums.size() - 1);    // Multiply by number of subset XOR totals that each bit set will have
    }
};
/*
solution reference
https://leetcode.com/problems/sum-of-all-subset-xor-totals/editorial
*/
