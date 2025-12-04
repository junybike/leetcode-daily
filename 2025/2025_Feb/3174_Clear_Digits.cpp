// 2025 Feb 10

class Solution {
public:

    // Checks if the character is a digit
    bool isDigit(char c)
    {
        return c >= '0' && c <= '9';
    }

    string clearDigits(string s) 
    {
        string ans = "";    // the string after clearing digits
        
        for (char& c : s)
        {
            // if the current character is not a digit, append to 'ans'
            if (!isDigit(c)) ans += c;  
            else 
            {
                // if the current character is a digit, remove the last character.
                // equivalent to deleting first digit and closest non digit character to its left
                ans.pop_back();
            }
        }
        return ans;
    }
};
