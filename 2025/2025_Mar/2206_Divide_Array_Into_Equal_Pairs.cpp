// 2025 Mar 17

class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map<short, short> umap;   // stores frequency of each values in 'nums'
        for (int i : nums)
        {
            // initialize umap
            umap[i]++;
        }    
        for (auto i : umap)
        {
            // If frequency of a value is not divisible by 2, a pair cannot be formed
            if (i.second % 2 != 0) return false;
        }
        return true;
    }
};
