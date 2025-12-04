// 2025 Jan 9

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int ans = 0;  // Number of words that contain 'pref' as its prefix
        for (string& s : words)
        {
            // Determine if the current word 's' has 'pref' as its prefix.
            // Increment 'ans' if so.
            auto res = mismatch(pref.begin(), pref.end(), s.begin());
            bool isprefix = (res.first == pref.end());
            if (isprefix) ans++;
        }
        return ans;
    }
};
