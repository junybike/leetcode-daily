// 2024 Oct 2

class Solution {

public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> ans;
        set<int> sorted;
        unordered_map<int, int> umap;

        for (int i : arr)
        {
            sorted.insert(i);
        }
        int index = 1;
        for (int i : sorted)
        {
            umap[i] = index;
            index++;
        }
        for (int i : arr)
        {
            ans.emplace_back(umap[i]);
        }
        return ans;
    }
};
