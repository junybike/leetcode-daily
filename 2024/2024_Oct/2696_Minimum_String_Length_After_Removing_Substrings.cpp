// 2024 Oct 7

class Solution {
public:
    int minLength(string s) 
    {
        // If length of s is 1, cannot remove substrings. Return 1.
        if (s.length() == 1) return 1;

        int index = 0;       // an index variable to traverse string
        int n = s.length();  // length of string s

        string temp = s;
        while (index + 1 < n)
        {
            // If substring AB or CD exists at the index, remove the substring from temp.
            // Resets index location and update n.
            if ((temp[index] == 'A' && temp[index + 1] == 'B') ||
                temp[index] == 'C' && temp[index + 1] == 'D')
            {
                string front = temp.substr(0, index);  // substring from the start of string to 'AB' or 'CD'
                string back = temp.substr(index + 2);  // substring from the end of 'AB' or 'CD' to end of string
                temp = front + back;                   // new string with removed substring 'AB' or 'CD'
                n = temp.length();
                index = 0;
            }
            else index++;  // increment index.
        }

        if (n == 0) return 0;  // If the length of final string is 0, return 0.
        return index + 1;      // If the length is not 0, add an extra one from the index, since the while condition is valid until index + 1 reaches n.
    }
};
