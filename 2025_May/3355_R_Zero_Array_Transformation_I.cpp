// 2025 May 20
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> delta(nums.size() + 1, 0);

        for (auto& arr : queries)   // for each arr (query), increases the value for delta[arr[0]] and decrease the value for delta[arr[1] + 1]
        {
            int L = arr[0];
            int R = arr[1];
            delta[L]++;
            delta[R + 1]--; 
        }

        vector<int> ops;
        int cur = 0;

        for (int i : delta)         // prefix sum. sum up each value in delta and record the sum whenever it updates
        {
            cur += i;
            ops.push_back(cur);
        }

        for (int i = 0; i < nums.size(); i++)   // at ith prefix sum, if it is less than num[i], zero array is not possible
        {
            if (ops[i] < nums[i]) return false;
        }

        return true;
    }
};
/*
solution reference
https://leetcode.com/problems/zero-array-transformation-i/editorial
*/
