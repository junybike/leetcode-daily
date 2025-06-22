// 2025 June 22
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string> ans;
        string str = "";

        for (int i = 0; i < s.length(); i++)    // append strings until string s gets out of characters
        {
            if (i % k == 0 && i != 0)
            {
                ans.push_back(str);
                str = "";
            }
            str += s[i];
        }

        if (str.length() != k)  // for unfinished last string, append with 'fill'
        {
            for (int i = 0; i < k - (s.length() % k); i++)
            {
                str += fill;
            }
        }
        ans.push_back(str);

        return ans;
    }
};
