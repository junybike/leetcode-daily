// 2025 Spet 15
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        unordered_set<char> uset;   // fast access to all broken letters
        for (char c : brokenLetters)
        {
            uset.insert(c);
        }

        bool broken = false;    // sign that the word cant be typed
        int ans = 0;            // number of words I can type
        text += ' ';            // add an extra space so the last word can be checked in the loop

        for (char c : text)
        {
            if (c == ' ')   // reset broken sign and check if previous word can be typed
            {
                if (!broken) ans++;
                broken = false;
                continue;
            }
            auto it = uset.find(c);             
            if (it != uset.end()) broken = true;    // if the character is found in uset, this word cant be typed
        }    
        return ans;
    }
};
