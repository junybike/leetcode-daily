// 2024 Sept 17

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string, int> umap;  // To store all words with its appearance count
        vector<string> ans;

        int size1 = s1.size();
        int size2 = s2.size();

        string word;

        for (int i = 0; i < size1; i++)
        {  
            // Gets the next word
            if (s1[i] != ' ')  
            {
                word += s1[i];
            }
            // Store the word in umap and/or increase its appearance count
            if ((s1[i] == ' ' && umap[word] >= 0) || ((i == size1 - 1) && umap[word] >= 0))
            {
                umap[word]++;
                word = "";
            }
        }
        word = "";

        for (int i = 0; i < size2; i++)
        {
            // Get the next word
            if (s2[i] != ' ')
            {
                word += s2[i];
            }
            // Store the word in umap and/or increase its appearance count
            if ((s2[i] == ' ' && umap[word] >= 0) || ((i == size2 - 1) && umap[word] >= 0)) 
            {
                umap[word]++;
                word = "";
            }
        }

        // Find words that have appeared once and add to ans.
        unordered_map<string, int>::iterator element;
        for (element = umap.begin(); element != umap.end(); element++)
        {
            if (element->second == 1) ans.push_back(element->first);
        }
        return ans;
    }
};
