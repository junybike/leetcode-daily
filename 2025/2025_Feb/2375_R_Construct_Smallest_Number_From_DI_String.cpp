// 2025 Feb 18

class Solution {
public:
    string smallestNumber(string pattern) 
    {
        short n = pattern.length(); // the length of pattern
        string ans;                 // the smallest number from DI string
        stack<int> st;              // stack to store numbers from 1 to n

        for (int i = 0; i <= n; i++)
        {
            st.push(i + 1); // push the current number to 'st'

            // If the current pattern is an I, append all numbers in 'st' to 'ans'
            if (i == n || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    ans += st.top() + '0';
                    st.pop();
                }
            }
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/construct-smallest-number-from-di-string/editorial
*/
