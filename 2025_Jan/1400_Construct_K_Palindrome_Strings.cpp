// 2025 Jan 11

class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        int characters[26] = {0};   // Stores the frequency of each alphabets
        int odd = 0;                // Keep track of odd number frequency of alphabets

        for (char & c : s)          // Compute the frequency of each alphabets
        {
            characters[c - 'a']++;
        }
        for (int i : characters)    // Record the amount of odd number of frequencies
        {
            if (i % 2 != 0) odd++;
        }

        // If the string length is less than k, not possible to form k palindrome using all characters in 's'.
        // If there are more odd number of frequencies than k, not possible to form k palindrome using all characters in 's'. 
        if (s.length() < k || odd > k) return false;
        return true;
    }
};
