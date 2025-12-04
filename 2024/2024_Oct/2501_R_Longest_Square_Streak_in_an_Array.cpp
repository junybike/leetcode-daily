// 2024 Oct 28

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end()); // Sorting 'nums' vector into ascending order
        map<int, int> mp;               // Save previously calculated square rooted values
        int ans = -1;                   // To store max number of subsequence
    
        for (int i : nums)
        {
            int temp = sqrt(i); // Squre root of a number 'i'

            // If temp^2 equals to the number 'i' (square root of 'i' is an integer)
            // and 'temp' exists in the map 'mp' (square root of 'i' was encountered before. therefore, forms a subsequence)
            // then increment the value of 'temp' in map and update 'ans' if one of mapped value is greater than 'ans'
            if (temp * temp == i && mp.find(temp) != mp.end())
            {
                mp[i] = mp[temp] + 1;
                ans = max(ans, mp[i]);
            }
            else mp[i] = 1; // Store an encountered value to map 'mp'
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/longest-square-streak-in-an-array/solutions/5976360/clean-and-fully-explained-code-step-by-step-breakdown
*/
