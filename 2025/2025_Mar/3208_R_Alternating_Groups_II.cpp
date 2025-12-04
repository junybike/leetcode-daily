class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int n = colors.size() + k - 1;  // size of colors and expanded extra k - 1 since 'colors' is a circular array 
        int groups = 0;                 // number of groups to return

        for (int i = 0; i < k - 1; i++) // fill the expanded spaces in 'colors'
        {
            colors.push_back(colors[i]);
        }

        int left = 0;   // the left-end index of the window
        int right = 1;  // the right-end index of the window

        while (right < n)
        {
            // if the two consecutive colors are same, 
            if (colors[right] == colors[right - 1])
            {
                left = right;   // set 'left' as 'right'
                right++;        // slide the window by incrementing 'right' 
                continue;
            }

            // if the adjacent values have different colors, only increment 'right'
            right++;
            if (right - left < k) continue; // if the window size is less than k, look at the next adjacent values

            // if the window size is k and no two adjacent same colors, increment group and slide the window by incrementing 'left' 
            groups++;
            left++;
        }
        return groups;
    }
};

/*
solution reference
https://leetcode.com/problems/alternating-groups-ii/editorial
*/
