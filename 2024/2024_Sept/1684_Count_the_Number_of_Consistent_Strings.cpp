// 2024 Sept 12 

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int ans = 0;
        unordered_map<char, int> umap;  // storing allowed characters

        // Find allowed characters
        for (int i = 0; i < allowed.size(); i++)
        {
            umap[allowed[i]] = 1;
        }

        // Check each characters for each words 
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (umap[words[i][j]] != 1) break;  // Contains not allowed characters
                if (umap[words[i][j]] == 1 && j == words[i].size() - 1) ans++;   // This word contains only allowed characters
            }
        }
        return ans;
    }
};
