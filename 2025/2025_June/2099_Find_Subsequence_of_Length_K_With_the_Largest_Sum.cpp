// 2025 June 28
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        vector<int> sorted = nums;  // sorted version of nums
        sort(sorted.begin(), sorted.end(), greater<int>());
        
        unordered_map<int, int> umap;   // store the first k greatest values in nums and their frequency
        for (int i = 0; i < k; i++)
        {
            umap[sorted[i]]++;
        }

        vector<int> subsequence;
        for (int i : nums)  // go through nums and whenever it encounters one of greatest values in nums, store in subsequence and decrement their frequency
        {
            if (umap[i])
            {
                umap[i]--;
                subsequence.push_back(i);
            }
        }
        return subsequence;
    }
};
