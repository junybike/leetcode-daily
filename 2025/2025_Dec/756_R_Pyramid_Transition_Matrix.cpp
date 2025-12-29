// 2025 Dec 29

class Solution {
public:

    unordered_map<string, vector<char>> umap;   // keep allowed strings and what it maps to
    unordered_map<string, bool> memo;           // to track each string if problem is solvable from it or not 

    bool solve(string bottom)
    {
        if (bottom.length() == 1) return true;          // if the length is 1, there is a solution
        if (memo.count(bottom)) return memo[bottom];    // if this is computed before, return its value. 

        vector<string> nextstr; // list of strings generated
        string cur = "";        // to generate string

        buildstr(bottom, 0, cur, nextstr);  // generate possible strings from 'bottom'

        for (string& s : nextstr)   // for each strings generated, check if they are solvable.
        {
            if (solve(s))
            {
                memo[bottom] = true;    // mark the memo true and return true.
                return true;
            }
        }

        // this string is not a solution. mark memo false and return false.
        memo[bottom] = false;
        return false;
    }

    void buildstr(string str, int idx, string cur, vector<string>& nextstr)
    {
        if (idx == str.length() - 1)    // string is generated. (the length is one less than str's)
        {
            nextstr.push_back(cur);
            return;
        }

        string s = "";
        s += str[idx];
        s += str[idx + 1];

        if (!umap.count(s)) return; // if this string is not part of the allowed, stop building strings.
        for (char c : umap[s])
        {
            cur.push_back(c);
            buildstr(str, idx + 1, cur, nextstr);   // build string on top of the current string
            cur.pop_back();                         // pop a character from the back to build other possible strings
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) 
    {
        // initialize keys for allowed patterns
        for (string& str : allowed)
        {
            string s = "";
            s += str[0];
            s += str[1];
            umap[s].push_back(str[2]);
        }

        return solve(bottom);
    }
};

// solution supported by chatgpt
