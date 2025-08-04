// 2025 Aug 4
class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> umap;
        int ans = 0;

        for (int i = 0, j = 0; j < fruits.size(); j++)
        {
            umap[fruits[j]]++;
            while (umap.size() > 2) // once 3 distinct fruits reached, remove one distinct fruits that appears earliest from the window
            {
                umap[fruits[i]]--;
                if (umap[fruits[i]] == 0) umap.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
