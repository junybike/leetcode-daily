// 2025 Dec 20

class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int cnt = 0;    // number of strings to erase
        for (int i = 0; i < strs[0].size(); i++)
        {
            char tmp = strs[0][i];  // a previous character to see if columns are sorted

            for (int j = 0; j < strs.size(); j++)
            {
                if (tmp <= strs[j][i]) tmp = strs[j][i];    // still sorted after next character  
                else                                        // this column is not sorted
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
