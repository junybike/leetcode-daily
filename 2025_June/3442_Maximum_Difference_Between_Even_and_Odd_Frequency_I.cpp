// 2025 June 10
class Solution {
public:
    int maxDifference(string s) 
    {
        int evens = INT_MAX;
        int odds = 0;

        vector<int> freq(26, 0);    // to record frequency of each characters
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            int cur = freq[i];

            if (cur % 2 == 0 && cur < evens && cur) evens = cur;    // find smallest non zero even number   
            else if (cur % 2 != 0 && cur > odds) odds = cur;        // find greatest odd number
        }

        return odds - evens;    // return maximum difference 
    }
};
