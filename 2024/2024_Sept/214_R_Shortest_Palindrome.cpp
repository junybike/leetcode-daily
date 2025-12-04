// 2024 Sept 20

class Solution {
public:
    string shortestPalindrome(string s) 
    {    
        // Reverse of string s and finds the length of longest palindrome in s. 
        string rev = s; 
        reverse(rev.begin(), rev.end());
        int count = kmp(rev, s);

        // Remaining part of s without the longest palindrome in s.
        string remains = rev.substr(0, s.length() - count);
        
        return remains + s;
    }

    // KMP Algorithm
    int kmp(const string &str, const string &pat)
    {
        // Reversed string s + '#' + string s
        string newstr = pat + '#' + str;

        // int array to keep track of the size of longest prefixes
        // i: front, k = prev index
        vector<int> lps(newstr.length(), 0);
        int i = 1, k = 0;

        while (i < newstr.length())
        {
            // if newstr[i] matches newstr[k], then increments k, store k to lps[i], and increments i
            if (newstr[i] == newstr[k])
            {
                k++;
                lps[i] = k;
                i++;
            }

            // else, and if k was greater than 0, k is lps[k - 1].  
            // Or if k is 0, lps[i] is set to 0 and increments i
            else
            {
                if (k > 0) k = lps[k - 1];
                else 
                {
                    lps[i] = 0; 
                    i++;
                }
            }
        }
        return lps.back();
    }
};

/*
Solution Reference
https://leetcode.com/problems/shortest-palindrome/solutions/5810352/beats-100-beginner-friendly-python3-java-c-c-ruby-go-javascript
*/
