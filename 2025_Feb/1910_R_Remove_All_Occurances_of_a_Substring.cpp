// 2025 Feb 11

class Solution {
public:

    // Checks if the stack's 'pn' recently pushed characters match 'part'
    bool checkMatch(stack<char> st, string& part, int pn)
    {
        stack<char> temp = st;
        for (int i = pn - 1; i >= 0; i--)
        {
            if (temp.top() != part[i]) return false;
            temp.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) 
    {
        stack<char> st;             // stores characters from 's'. pop if it contains 'part'
        short sn = s.length();      // length of 's'
        short pn = part.length();   // length of 'part'

        for (int i = 0; i < sn; i++)
        {
            st.push(s[i]);

            // If the stack holds more than or equal to pn character, 
            // check if 'pn' recently pushed characters match 'part' string
            if (st.size() >= pn && checkMatch(st, part, pn))
            {
                // pop 'pn' recently pushed characters
                for (int j = 0; j < pn; j++)
                {
                    st.pop();
                }
                
            }
        }

        // append all characters in stack to a single string
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

/*
solution referencne
https://leetcode.com/problems/remove-all-occurrences-of-a-substring/editorial
*/
