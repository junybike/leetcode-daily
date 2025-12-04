// 2024 Nov 3

class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        // Case: Returns false when string 's' and 'goal' have different length.
        if (s.length() != goal.length()) return false;

        string substring = "";  // To store substring
        bool sign = true;       // A bool sign.

        for (char c : s)
        {
            // Add a character one by one from string 's' to the 'substring'
            // If the 'substring' is not detected in goal, resets 'substring'
            // and start to add the remaining characters from string 's'.
          
            // The 'sign' turns false when 'substring' is not detected in goal to prevent
            // the if statement to go through again later.
          
            substring += c;
            if (sign && goal.find(substring) == string::npos) 
            {
                substring = "";
                substring += c;
                sign = false;
            }
        }

        // If the 'substring' formed from remaining characters exists in 'goal' after resetting the substring, 
        // then it is valid. Returns True. Else, returns false. 
        return goal.find(substring) != string::npos;
    }
};
