// 2025 Sept 11
class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char> vowels;    // store all vowels in s
        for (char c : s)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                vowels.push_back(c);
            }
        }    
        sort(vowels.begin(), vowels.end()); // sort the vowels lexicographically

        for (int i = 0, j = 0; i < s.length(); i++) // replace all vowels at s[i] with vowels[j]
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = vowels[j];
                j++;
            }
        }
        return s;
    }
};
