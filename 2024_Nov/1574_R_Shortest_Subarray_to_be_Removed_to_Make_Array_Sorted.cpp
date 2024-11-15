// 2024 Nov 16

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int n = arr.size();

        // Find the longest non decreasing prefix from the first value in 'arr'
        // 'L' represents the end index of prefix (range would be 0 to L)
        int L = 0;
        while (L < n - 1 && arr[L] <= arr[L + 1]) L++;

        // The case when the values in 'arr' is already sorted
        if (L == n - 1) return 0;

        // Find the longest non decreasing suffix from the end value in 'arr'
        // 'R' represents the starting index of suffix (range would be R to n - 1)
        int R = n - 1;
        while (R > 0 && arr[R - 1] <= arr[R]) R--;

        // Determine the default number of values to remove by removing the prefix or suffix.
        // Later, try to find a smaller number of values to remove from the middle values.
        int ans = 0;
        if (n - L - 1 < R) ans = n - L - 1;
        else ans = R;

        // Try to find the smaller number of values to be removed than min(prefix, suffix)
        int i = 0;
        int j = R;
        while (i <= L && j < n)
        { 
            // If the value at 'i' index is not greater than the value at the right pointer 'j',
            // shrink the range of numbers by incrementing the left pointer.  
            // Update the 'ans' if the current range is shorter than the previous range 
            if (arr[i] <= arr[j]) 
            {
                ans = min(ans, j - i - 1);
                i++;
            }
            // If the value at 'i' index is greater than the value at the right pointer 'j',
            // widen the range of numbers by incrementing the right pointer. 
            // This is to make sure that the 'arr' remains sorted when deleting the current range of values.
            else j++;
        }

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solutions/6046262/beats-100-00-easy-and-step-by-step-breakdown
*/
