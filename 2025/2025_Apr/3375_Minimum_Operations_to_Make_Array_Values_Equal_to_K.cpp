class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, bool> umap;  // store values appeared in 'nums'
        for (int i : nums)
        {
            if (i < k) return -1;               // if a value smaller than k appears, return -1
            else if (i > k) umap[i] = true;     // if a value larger than k appears, store in umap
        }
        return umap.size(); // number of distinct values appeared in 'nums'
    }
};
