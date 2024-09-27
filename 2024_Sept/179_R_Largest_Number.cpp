// 2024 Sept 18

class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string> array;
        string ans;

        // Push all string converted nums into the array vector
        for (int i : nums)
        {
            array.push_back(to_string(i));
        }

        // Sort the array vector with condition of (b + a) < (a + b)
        sort(array.begin(), array.end(), [](const string &a, const string &b)
        {
            return (b + a) < (a + b);
        });

        // If the largest num is 0, then return 0.
        if (array[0] == "0") return "0";

        // Add sorted string typed nums into the answer string 
        for (string str : array) ans += str;

        return ans;
    }
};

/*
Solution Reference
https://leetcode.com/problems/largest-number/solutions/5802128/sort-w-r-t-the-proper-ordering-by-string-or-arithmetic-way-beats-100
*/
