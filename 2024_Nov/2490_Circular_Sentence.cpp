// 2024 Nov 2

class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
        // A stringstream to get word by word from string 'sentence'.
        // Each word is separated by a space
        string word;
        stringstream iss(sentence);

        char first = sentence[0];  // First ever character from the sentence 'string'

        // To check the last character of each word. 
        // Initially set to first character of first word to satisfy the first iteration of the while loop
        char prev = sentence[0];   
        while (iss >> word)
        {
            // If the current word's first character is not the same as last word's last character, return false.
            if (word[0] != prev) return false;  
            prev = word.back(); // Update the last character to compare.
        }

        // If the 'first' character and last word's last character in 'sentence' string is the same, return true. Else, false.
        return word.back() == first;
    }
};
