// 2025 Mar 10

class Solution {
public:

    // check if a character is a vowel
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countOfSubstrings(string word, int k) 
    {
        unordered_map<char, int> vowels;    // store the vowels encountered in a window
        int n = word.length();              // word length
        int con = 0;                        // number of consonants
        long long ans = 0;                  // number of valid substrings

        vector<int> nextCon(n);             // stores index of next consonant at each index
        int nextConIndex = n;               // tracks the next consonant index

        // Initializes 'nextCont'
        for (int i = n - 1; i >= 0; i--)
        {
            nextCon[i] = nextConIndex;
            if (!isVowel(word[i])) nextConIndex = i;
        }

        int L = 0;  // start index of the window
        int R = 0;  // end index of the window

        while (R < n)
        {
            if (isVowel(word[R])) vowels[word[R]]++;    // if a vowel is encountered, increase the vowel count
            else con++;                                 // else, increase the consonant count
            
            while (con > k)             // case where 'con' exceeded 'k' 
            {
                if (isVowel(word[L]))   // if a char at 'L' is a vowel, update 'vowels'
                {
                    vowels[word[L]]--;
                    if (vowels[word[L]] == 0) vowels.erase(word[L]);
                }
                else con--;             // else, decrement 'con'

                L++;                    // update the window by increasing 'L'
            }   

            // case where current window contains the valid substring
            while (L < n && vowels.size() == 5 && con == k)
            {
                ans += nextCon[R] - R;  // increment 'ans' just before it encounters the next consonant
                if (isVowel(word[L]))   // to slide the window, if the char at 'L' is vowel, update 'vowels'
                {
                    vowels[word[L]]--;
                    if (vowels[word[L]] == 0) vowels.erase(word[L]);
                }
                else con--;             // else, decrement 'con'

                L++;    // update start index of window 
            }
            R++;        // update end index of window
        }    
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/editorial
*/
