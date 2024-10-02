// 2024 Oct 2

class Solution {

public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> ans;                // To assign the rank of each element in the order of appearance of the element in the arr
        set<int> sorted;                // Sorted set of arr in ascending order
        unordered_map<int, int> umap;   // To store the ranks of each elements

        // Insert each element into the sorted set
        for (int i : arr)
        {
            sorted.insert(i);
        }

        // Store the rank for each element
        int index = 1;
        for (int i : sorted)
        {
            umap[i] = index;
            index++;
        }

        // Assign the rank and return
        for (int i : arr)
        {
            ans.emplace_back(umap[i]);
        }
        return ans;
    }
};
