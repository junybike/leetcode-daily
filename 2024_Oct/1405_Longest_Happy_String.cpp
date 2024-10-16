// 2024 Oct 16

class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        // Store the available number of a, b, and c in vector of pairs. (in descending order)
        vector<pair<int, char>> vec;
        vec.push_back(make_pair(a, 'a'));
        vec.push_back(make_pair(b, 'b'));
        vec.push_back(make_pair(c, 'c'));
        sort(vec.begin(), vec.end(), std::greater<>());

        int len = 0;       // keep track of the length of string
        string ans = "0";  // the string to build on (0 is a dummy character which will be excluded when returning)
        
        // Loop as long as one of character is still available 
        while (vec[0].first > 0 || vec[1].first > 0 || vec[2].first > 0)
        {
            // Add the most remaining character twice to ans if it is available and the previous character isn't this character. 
            if (vec[0].first > 1 && ans[len] != vec[0].second)
            {
                ans = ans + vec[0].second + vec[0].second;
                vec[0].first -= 2;
                len += 2;
            }
              
            // This case gets checked if there is only one character remaining and one is the largest remaining amount of all characters.
            // Add this character once to ans if the previous character is this character and the prev prev character is not this character
            // or the previous character is not this character.
            else if (vec[0].first >= 1 && (ans[len] != vec[0].second || ans[len - 1] != vec[0].second))
            {
                ans = ans + vec[0].second;
                vec[0].first--;
                len += 1;
            }

            // If there is another character remaining, get the second most remaining character and add this character once to ans.
            // No need to check for previous character since this case runs after adding another character to ans.
            if (vec[1].first >= 1)
            {
                ans = ans + vec[1].second;
                vec[1].first--;
                len += 1;
            }

            // If the above cases are not valid, cannot add any more characters. Stop the loop and return the string.
            else break;
            
            // Update the order of pairs based on their amount of remaining characters.
            sort(vec.begin(), vec.end(), std::greater<>());
        }
      
        return ans.substr(1);
    }
};
