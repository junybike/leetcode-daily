// 2025 Feb 26

class Solution {
public:

    // KADANE'S ALGORITHM
    
    // finds maximum subarray sum in an array
    int maxSubarraySum(vector<int> &arr) 
    {
        int res = arr[0];
        int maxEnding = arr[0];

        for (int i = 1; i < arr.size(); i++) 
        {
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }

    // finds minimum subarray sum in an array
    int minSubarraySum(vector<int> &arr)
    {
        int res = arr[0];
        int minEnding = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            minEnding = min(minEnding + arr[i], arr[i]);
            res = min(res, minEnding);
        }
        return res;
    }

    int maxAbsoluteSum(vector<int>& nums) 
    {
        int maxsum = maxSubarraySum(nums);      // the maximum subarray sum in 'nums'
        int minsum = abs(minSubarraySum(nums)); // the minimum subarray sum in 'nums'
        
        // since it is asking for absolute sum, compare
        // 'maxsum' and absolute value of 'minsum' and return the larger one.
        if (maxsum > minsum) return maxsum;
        else return minsum;
    }
};
