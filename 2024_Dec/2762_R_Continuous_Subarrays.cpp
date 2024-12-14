// 2024 Dec 14

// TLE :(
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        int n = nums.size();  // Size of 'nums'
        int range = 1;        // Size of subarrays to check
        int ans = n;          // Number of valid subarrays

        // Check subarrays length 1 to n
        while (range < n)
        {
            for (int L = 0, R = 0; R < n; R++)
            {
                int low = *min_element(nums.begin() + L, nums.begin() + R + 1);   // Get the lowest value in this subarray
                int high = *max_element(nums.begin() + L, nums.begin() + R + 1);  // Get the highest value in this subarray

                // Maintaining the window (keep its range)  by increasing 'L' pointer.
                if (R - L >= range)
                {
                    L++;
                    if (high - low <= 2) ans++; // If 'high' - 'low' is less than 3, it is a valid subarray. Increment ans.
                } 
            }
            range++;
        }
        return ans;    
    }
};

class RSolution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        map<int, int> freq;     // Stores sorted frequency map for each sliding window iteration
        int n = nums.size();    // Size of 'nums'

        int L = 0;              // Left pointer in 'nums'
        int R = 0;              // Right pointer in 'nums'
        long long ans = 0;      // Number of subarrays to return

        while (R < n)
        {
            freq[nums[R]]++;    // Record current value to 'freq' 

            // If there is an invalid subarray (|nums[i] - nums[j]| <= 2),
            // shrink the range by increasing pointer 'L' 
            while (freq.rbegin()->first - freq.begin()->first > 2)
            {
                freq[nums[L]]--;    // Remove the value that are out of range. 
                if (freq[nums[L]] == 0) freq.erase(nums[L]);
                L++;
            }

            ans += R - L + 1;   // Sum up number of valid subarrays 
            R++;
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/continuous-subarrays/solutions/6140505/continuous-subarrays
*/
