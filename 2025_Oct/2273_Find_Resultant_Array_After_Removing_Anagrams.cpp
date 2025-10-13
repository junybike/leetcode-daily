// 2025 Oct 13
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        for (int i = words.size() - 1; i > 0 ; i--)
        {
            string a = words[i];
            string b = words[i - 1];
            
            if (a.size() != b.size())   // if they have different size, they cant be anagram
            {
                continue;
            }   

            sort(a.begin(), a.end());   // sort both strings alphabetically
            sort(b.begin(), b.end());

            if (a == b) // if they are equal, remove words[i]
            {
                words.erase(words.begin() + i);
            }
        }    
        return words;
    }
};
