// 2025 June 19
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int prev = nums[0]; // keep track of lowest value in a subarray
        int cnt = 1;        // count the number of subarray

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - prev <= k) continue;  // if max diff is lower or equal to k, continue
            else
            {
                prev = nums[i]; // if greater than k, update prev to current value. (virtually moving onto next subarray)
                cnt++;
            }
        }
        return cnt;
    }
};
