// 2025 Sept 8
class Solution {
public:

    bool isZero(int n)  // check if theres a 0 in n
    {
        string str = to_string(n);
        for (char c : str)
        {
            if (c == '0') return true;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) 
    {
        for (int i = 0; i < n; i++) // check if (i, n - i) are valid pair
        {
            if (!isZero(i) && !isZero(n - i)) return {i, n - i};
        }    
        return {};
    }
};
