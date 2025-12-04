// 2025 July 15

class Solution {
public:

    bool isVowel(char c)    // check if a character is a vowel
    {
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
            (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) return true;
        return false;
    }
    bool isEng(char c)  // check if a character is an alphabet
    {
        if ((c == '@') || (c == '#') || (c == '$') || (c >= '0' && c <= '9')) return false;
        return true;
    }
    bool isNum(char c)  // check if a character is a number 
    {
        if ((c >= '0' && c <= '9')) return true;
        return false;
    }

    bool isValid(string word) 
    {
        if (word.length() < 3) return false;

        bool vowel = false; // word contains a vowel
        bool cons = false;  // word contains a consonent
            
        for (char c : word)
        {
            if (isVowel(c)) vowel = true;
            if (!isVowel(c) && isEng(c)) cons = true;
            if (!isEng(c) && !isNum(c)) return false;   // contains a non alphabet and non number character
        }

        return vowel && cons;
    }
};
