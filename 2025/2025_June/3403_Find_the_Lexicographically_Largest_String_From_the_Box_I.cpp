// 2025 June 5
class Solution {
public:
    string answerString(string word, int numFriends) 
    {
        if (numFriends == 1) return word;   // if one friend, no need to split
        
        char large_c = 'a'; // find the lexicographically largest character
        for (char c : word)
        {
            if (c > large_c) large_c = c;
        }

        int n = word.length();  
        string str = "";
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == large_c)  
            {
                // for each large_c found in the 'word', check if the substring from the current word to the end of 'word' is larger than 'str'
                // remove characters from the end if the length is larger than n - numFriends (if larger, not large enough to split)
                string sub = word.substr(i);
                if (sub.length() >= n - numFriends + 1) sub = sub.substr(0, n - numFriends + 1);
                if (sub > str) str = sub;  
            }
        }

        return str;
    }
};
