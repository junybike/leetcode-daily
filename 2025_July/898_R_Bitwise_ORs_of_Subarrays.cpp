// 2025 July 31
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int> res;     // stores unique values
        unordered_set<int> prev;    // keeps the unique values after each iteration
        int n = arr.size();

        for (int i : arr)
        {
            unordered_set<int> cur; // unique values found in this iteration
            cur.insert(i);

            for (int p : prev)      // perform bitwise OR with current value with all previous unique values 
            {
                cur.insert(i | p);
            }
            prev = cur;

            for (int c : cur)       // stores unique values found
            {
                res.insert(c);
            }
        }
        return res.size();
    }
};

/*
solution reference
ChatGPT
*/
