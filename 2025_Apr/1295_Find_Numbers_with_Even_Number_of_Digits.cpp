// 2025 Apr 30
class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int cnt = 0;
        for (int i : nums)
        {
            int size = trunc(log10(i)) + 1;  // find the length of the integer
            if (size % 2 == 0) cnt++;        // check if it is even
        }    
        return cnt;
    }
};
