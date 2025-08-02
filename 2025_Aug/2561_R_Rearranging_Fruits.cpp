// 2025 Aug 2
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        int val = INT_MAX;              // min value from basket1 / basket2
        unordered_map<int, int> umap;   

        for (int i : basket1)
        {
            umap[i]++;
            val = min(val, i);
        }
        for (int i : basket2)
        {
            umap[i]--;
            val = min(val, i);
        }

        vector<int> v1;
        for (auto [a, b] : umap)
        {
            if (b % 2 != 0) return -1;              // if the frequency is not even, the two baskets cannot be equal 
            for (int i = 0; i < abs(b) / 2; i++)    // find possible swaps and store in v1
            {
                v1.push_back(a);
            }
        }

        sort(v1.begin(), v1.end());
        long ans = 0;
        for (int i = 0; i < v1.size() / 2; i++) // sum up the costs of minimum swaps
        {
            ans += min(2 * val, v1[i]);
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/rearranging-fruits/editorial
*/
