// 2024 Nov 1

class Solution {
public:
    string makeFancyString(string s) 
    {
        int n = s.length();    // The length of string s
        int count = 1;         // To keep count of consecutive character
        char temp = s[n - 1];  // Set previous character to first character of string

        // Iterate from the back of string s
        for (int i = n - 2; i >= 0; i--)
        {
            // If current character is same as previous,
            // check if it has appeared for 3 or more times. 
            // If then, delete the character from the string s.
            // Increment the count.
            if (s[i] == temp)
            {
                count++;
                if (count >= 3) s.erase(s.begin() + i);
            }
            // If not the same as previous,
            // change previous character to current character.
            // Reset count to 1.
            else
            {
                temp = s[i];
                count = 1;
            }
        }
        return s;
    }
};

//-----------------------------------------------------------

class Solution2 {
public:
    string makeFancyString(string s) 
    {
        string ans;        // The string to return
        int count = 1;     // To keep count of consecutive character
        char temp = '0';   // Set previous character to '0'

        for (char c : s)
        {
            // If current character is not the same as previous,
            // Append the character to ans.
            // Update previous character to current and reset count to 1.
            if (c != temp)
            {
                ans += c;
                temp = c;
                count = 1;
            }
            // If current character is the same as previous and 
            // count is less than 2, append the character to ans and increment the count.
            // Othewise, does nothing.
            else
            {
                if (count < 2)
                {
                    ans += c;
                    count++;
                } 
            }
        }

        return ans;
    }
};
