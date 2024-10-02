// 2024 Oct 2

class Solution {

public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        unordered_map<int, int> umap;                // To store the rank of each elements in arr
        vector<int> sorted{arr.begin(), arr.end()};  // A copy of arr
        sort(sorted.begin(), sorted.end());          // Sorts the copy of arr in ascending order 

        // Assign the rank for each elements
        int rank = 1;
        for (int i : sorted)
        {
            if (umap[i] == 0)
            {
                umap[i] = rank;
                rank++;
            }
        }

        // Overwrites arr with the rank of each elements
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = umap[arr[i]];
        }

        return arr;
    }
};

/*
Solution reference
Leetcode Code Sample
*/
