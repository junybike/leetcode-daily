// 2024 Nov 4

class Solution {
public:
    string compressedString(string word) 
    {
        string comp = "";    // the string to return
        char prev = word[0]; // store the previous character in 'word' 
        int count = 0;       // a counter

        int i = 0;           // string index for 'word'
        while (i < word.length())
        {
            // increment 'counter' and string index 'i' until the counter reaches 9 
            // or the previous character does not match with character at word[i]
            while (count < 9 && prev == word[i])
            {
                count++;
                i++;
            }
            comp += (to_string(count) + prev);  // append the 'count' value and the previous character to 'comp'
            prev = word[i];                     // set the previous character to the character at current index 'i'
            count = 0;                          // reset the counter to 0
        }
        
        return comp;
    }
};
