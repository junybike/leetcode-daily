// 2024 Dec 2

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        string word = "";           // A word to check in 'sentence'
        int space = 1;              // the 'searchWord' is found in ith (space) word in 'sentence' 
        int n = sentence.length();  // the length of 'sentence'

        for (int i = 0; i < n; i++)    
        {   
            word += sentence[i];    // Add character by character until it reaches a space
            
            // If the current character is a space or the end character,
            // check if the 'searchWord' is located at the beginning of 'word'.
            // If located at the beginning, return the 'space'.
            // Else, increment the 'space' and reset the 'word'.
            if (sentence[i] == ' ' || i == n - 1) 
            { 
                if (word.find(searchWord) == 0) return space;
                space++;
                word = "";
            }
        }

        // No searchWord is found at any beginning of 'word'
        return -1;
    }
};
