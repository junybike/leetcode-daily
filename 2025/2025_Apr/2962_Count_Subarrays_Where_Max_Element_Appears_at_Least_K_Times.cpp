// 2025 Apr 29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long cnt = 0;      // counts the number of greatest value in a subarray 
        long long ans = 0;      // count the number of valid subarrays

        int max_val = 0;
        for (int i : nums)  // finds the greatest value in 'nums'
        {
            if (i > max_val) max_val = i;
        }

        for (int i = 0, j = 0; j < n; j++)
        {
            if (nums[j] == max_val) cnt++;  // increment cnt if encounters the greatest value

            while (i <= j && cnt >= k)          // shrink the subarray range until cnt is (k - 1)
            {   
                if (nums[i] == max_val) cnt--;
                i++;
                cout << i << " " << j << endl;
            }
            ans += i;   // add number of total subarray possible based on starting border
        }
        return ans;
    }
};
