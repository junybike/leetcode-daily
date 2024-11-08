class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int> ans;                      // To store the k for each query
        int query = 0;                        // XORs number in nums every iterations
        int maxnum = (1 << maximumBit) - 1;   // max value that each query can reach to with the 'maximumBit'

        for (int i : nums)
        {
            query = query ^ i;              // XORs number i every iteration to compute maximized k for each query
            ans.push_back(query ^ maxnum);  // Stores the k value that maximizes nums[0] XOR ... XOR nums[?] XOR k
                                            // (query XOR maxnum) determines what k value can maximizes the query
        }

        reverse(ans.begin(), ans.end());    // Reverse the 'ans' vector, since the query is iterated from shortest to longest
        return ans;
    }
};
