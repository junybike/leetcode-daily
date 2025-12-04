// 2025 Feb 19

class Solution {
public:

    void makestring(int n, string cur, vector<string>& happystr)
    {
        if (cur.size() == n)    // If the 'cur' is a length of n, store this string to 'happystr'
        {
            happystr.push_back(cur);
            return;
        }
        for (char c = 'a'; c <= 'c'; c++)   // Generating happy strings
        {
            if (cur.size() > 0 && cur.back() == c) continue;
            makestring(n, cur + c, happystr);
        }
    }

    string getHappyString(int n, int k) 
    {               
        vector<string> happystr;        // To store all happy strings
        makestring(n, "", happystr);    // Start making happy strings from empty string

        if (happystr.size() < k) return "";     // If there are less than 'k' happy strings, returns empty string.
        sort(happystr.begin(), happystr.end()); // Sort the happy strings to find the kth lexicographical string

        return happystr[k - 1];   
    }
};
/*
solution reference
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/editorial
*/
