// 2025 Sept 13
class Solution {
public:
    int maxFreqSum(string s) 
    {
        unordered_map<char, int> vowels;
        unordered_map<char, int> cons;

        for (char c : s)  // count frequency of each vowels and cons
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vowels[c]++;
            }
            else
            {
                cons[c]++;
            }
        }    

        int a = 0;
        int b = 0;

        for (auto& i : vowels)  // find the most common vowel
        {
            if (a < i.second) a = i.second;
        }
        for (auto& i : cons)  // find the most common cons
        {
            if (b < i.second) b = i.second;
        }
        return a + b;
    }
};
