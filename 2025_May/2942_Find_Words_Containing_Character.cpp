// 2025 May 24
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) 
    {
        vector<int> ans;    // store index for word in words
        int i = 0;          // index to traverse in words
        for (string& s : words)
        {
            for (char c : s)
            {
                if (c == x) // check if this string contains character x
                {
                    ans.push_back(i);   
                    break;
                }
            }
            i++;
        }
        return ans;    
    }
};
