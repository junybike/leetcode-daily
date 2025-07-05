// 2025 July 5
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> umap;   // find out frequencies for each values in arr
        for (int i : arr)
        {
            umap[i]++;
        }   

        int ans = -1; 
        for (auto& i : umap)    // find largest lucky integer 
        {
            if (i.first == i.second && i.first > ans) ans = i.first;
        }

        return ans;
    }
};
