// 2025 June 6
class Solution {
public:
    string robotWithString(string s) 
    {
        unordered_map<char, int> cnt;   // tracks frequency for each character  
        for (char c : s)
        {
            cnt[c]++;
        }

        stack<char> stk;    // stores characters from s each iteration
        string p;           // possible lexico lowest string
        char minchar = 'a'; // keep track of current min char available each iteration

        for (char c : s)
        {
            stk.push(c);
            cnt[c]--;

            // adjust to the current minchar available
            while (minchar != 'z' && cnt[minchar] == 0)
            {
                minchar++;
            }

            // if at the top of stack, has the lower minchar, pop the character from stack and append to p
            while(!stk.empty() && stk.top() <= minchar)
            {
                p.push_back(stk.top());
                stk.pop();
            }
        }
        return p;
    }
};
/*
solution reference
https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/editorial
*/
