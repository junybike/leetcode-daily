// 2025 Feb 6

class Solution {
public:

    int tupleSameProduct(vector<int>& nums) 
    {
        unordered_map<int, int> umap;   // Stores the frequency of products of two distinct values in 'nums'
        int n = nums.size();            // the size of 'nums'
        int ans = 0;                    // number of possible tuples

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                umap[nums[i] * nums[j]]++;  // records the products of two distinct values
            }
        }    

        for (auto& i : umap)
        {
            // (Each pair can form 8 tuples) * (number of ways to choose two pairs with same product)
            ans += 8 * ((i.second - 1) * i.second / 2);
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/tuple-with-same-product/editorial
*/
