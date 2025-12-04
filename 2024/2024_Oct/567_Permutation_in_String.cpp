// 2024 Oct 5

class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> vec(26, 0);    // Stores each character's number of appearance in s1
        vector<int> zeros(26, 0);  // Vector with all 0
        int n = s2.length();       // s2 string length

        // Count each character's appearance in s1
        for (char c : s1)
        {
            vec[c - 'a']++;
        }    

        // Check starting from each indexes
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = vec;
            for (int j = i; j < n; j++)
            {
                // If the character exists at this index and the count is non zero
                // decrement the count by one in temp vector.
                // If temp vector contains all zero, a permutation exists. Return true.
                if (temp[s2[j] - 'a'] > 0)
                {
                    temp[s2[j] - 'a'] = temp[s2[j] - 'a'] - 1;
                    if (temp == zeros) return true;
                }
                // If this character cannot be appeared again, no permutation at ith index.
                // Move on to next index.
                else if (temp[s2[j] - 'a'] == 0)
                {
                    break;
                }
            }
        }
        return false;
    }
};
