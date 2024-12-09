class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();        // Size of 'nums'
        vector<int> prefix(n, 0);   // Contains prefix sum. (The amount of same parity encountered)
        vector<bool> ans;           // Contains special array indicators for each queries. 

        for (int i = 1; i < n; i++)
        {
            // Set the value at index i in 'prefix' as the value at index i - 1.
            // If the parity at nums[i] and nums[i - 1] is different, increment the prefix sum at prefix[i].
            prefix[i] = prefix[i - 1];  
            if ((nums[i - 1] & 1) == (nums[i] & 1)) prefix[i]++;
        }

        for (auto& q : queries)
        {
            // If the difference of prefix sum at starting point and end point at a query are the same,
            // no adjacent values with same parity were encountered.
            // Record true when no adjacent values with same parity were encountered. Record false otherwise.  
            int count = prefix[q[1]] - prefix[q[0]];
            ans.push_back(count == 0);
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/special-array-ii/solutions/6127355/simple-prefix-solution-100-beats
*/
