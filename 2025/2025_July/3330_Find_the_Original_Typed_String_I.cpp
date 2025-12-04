// 2025 July 1
class Solution {
public:
    int possibleStringCount(string word) 
    {
        int cnt = 1;
        char prev = word[0];    // keep track of the prev character for being typed multiple times
        
        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] == prev) cnt++; // every character typed multiple times are possible word. increment cnt whenever it is typed multiple times
            else prev = word[i];        // update the prev char if different char is typed
        }    

        return cnt;
    }
};
