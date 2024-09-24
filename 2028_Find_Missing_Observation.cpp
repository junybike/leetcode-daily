class Solution 
{
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        vector<int> more_rolls(n, 0);
        int size = rolls.size() + n;  
        int sum = 0;
        int add = size;
        int remain = 0;

        // Total sum of given rolls
        for (int i : rolls)
        {
            sum += i;
        }
        
        remain = mean * size - sum;
        add = remain / n;

        // Impossible case. 
        // The average value has to be either less than 1 or greater than 6 to match the average (mean). 
        if (add < 1 || add > 6) return {};

        // Add the missing rolls with by adding (remain / n)
        // This is a partial step to complete the missing values
        for (int i = 0; i < n; i++)
        {
            sum += add;
            more_rolls[i] = add;
        }

        // Number of values need to be incremented by 1 to match the average (mean)
        remain = mean * size - sum;
      
        // Impossible case.
        // Too many values needs to be incremented by 1
        if (remain > n) return {};

        // Adding an extra one 
        for (int i = 0; i < remain; i++)
        {
            more_rolls[i]++;
            // If a value exceeds 6 while getting incremented, then this is an impossible case.
            if (more_rolls[i] > 6) return {};
        }

        return more_rolls;
    }
};
