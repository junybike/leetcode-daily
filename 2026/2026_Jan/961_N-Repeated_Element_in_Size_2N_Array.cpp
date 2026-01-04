// 2025 Jan 2
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int, int> umap;  // keep track of each values' occurence in nums
        int n = nums.size();
        
        for (int i : nums)
        {
            umap[i]++;
            if (umap[i] == n / 2) return i;  // if a value has n/2 occurence, return that value
        }    
        return -1;
    }
};
