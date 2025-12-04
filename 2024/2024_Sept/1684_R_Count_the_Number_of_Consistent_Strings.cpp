// 2024 Sept 12

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        vector<int> hmap(26, 0);  // To store allowed characters
        int count = 0;

        // Mark allowed characters 
        for (char c : allowed)
        {
            hmap[c - 'a'] = 1;
        }

        for (string str : words)
        {
            bool valid = true;
            for (char c : str)
            {
                if (hmap[c - 'a'] == 0)  // Case for not allowed character.  
                {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;  // Case when the word only contains allowed characters
        }
        return count;
    }
};

/*
Solution Reference:
Code Sample in 45 ms Runtime
*/
