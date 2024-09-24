// 2024 Sept 2

class Solution 
{
public:
    
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        long chalkneeded = 0;
        for (int i : chalk)
        {
            chalkneeded += i;
        }
        // This part eliminates unnecessary calculation of full traversal of chalk array. 
        int chalkremaining = k % chalkneeded;

        for (int i = 0; i < chalk.size(); i++)
        {
            if (chalkremaining < chalk[i]) return i;
            chalkremaining -= chalk[i];
        }
        return 0;
    }
};
