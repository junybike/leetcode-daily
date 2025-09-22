// 2025 Sept 22
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int, int> umap1;  // store frequency of each values in nums
        unordered_map<int, int> umap2;  // store frequency of frequencies of values in nums
        for (int i : nums)
        {
            umap1[i]++;
        }

        int maximum = 0;
        for (auto& i : umap1)
        {
            umap2[i.second]++;
            if (i.second > maximum) maximum = i.second;
        }

        return umap2[maximum] * maximum;
    }
};
