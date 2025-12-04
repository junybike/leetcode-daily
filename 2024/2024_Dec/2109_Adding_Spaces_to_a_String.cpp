// 2024 Dec 3

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string ans = "";            // The space applied string to return
        int index = 0;              // An index indicator in string 's'
        int s_index = 0;            // An index indicator in vector 'spaces'
        int s_size = spaces.size(); // The size of vector 'spaces'

        for (char c : s)
        {
            // If a space is required on this index, add a space to 'ans'
            if (index == spaces[s_index]) 
            {
                // If the last space in 'spaces' has not been reached, 
                // update the next index where space is needed
                if (s_index != s_size - 1) s_index++;   
                ans += ' ';
            }

            // Append the next character in 's' and update 'index'
            ans += c;
            index++;
        }
        return ans;
    }
};
