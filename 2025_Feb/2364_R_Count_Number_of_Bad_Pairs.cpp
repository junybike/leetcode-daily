// 2025 Feb 9

class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        unordered_map<int, int> umap;   // records frequency of i - nums[i]
        long long ans = 0;              // number of bad pairs

        for (int i = 0; i < nums.size(); i++)
        {
            int dif = i - nums[i];
            int goodpairs = umap[dif];  // prev pos with same difference

            ans += i - goodpairs;       // total valid pairs - goodpairs = bad pairs
            umap[dif] = goodpairs + 1;  // updates position count
        }    
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/count-number-of-bad-pairs/submissions/1536367235
*/
