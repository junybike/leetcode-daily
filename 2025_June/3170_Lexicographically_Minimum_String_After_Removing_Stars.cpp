class Solution {
public:

    string clearStars(string s) 
    {
        // for each character, store its indexes in s in decreasing order
        unordered_map<char, priority_queue<int>> umap; 

        for (int i = 0; i < s.length(); i++)
        {
            // if * is encountered, find the lexico lowest character available from its left
            // and mark it as '!'
            if (s[i] == '*')    
            {
                for (int j = 0; j < 26; j++)    // finding the availabe lexico lowest
                {
                    if (!umap[j + 'a'].empty())
                    {
                        int index = umap[j + 'a'].top();
                        s[index] = '!';
                        umap[j + 'a'].pop();
                        break;
                    }
                }
            }
            else umap[s[i]].push(i);    // store its index in umap
        }

        string ans = "";    // append each characters from s except the ones marked with '!' and * 
        for (char c : s)
        {
            if (c != '!' && c != '*') ans += c;
        }
        return ans;
    }
};
