// 2024 Dec 19

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        short sum = 0;      // Records the prefix sum of values in 'arr'
        short ans = 0;      // Amount of partitions need to be made

        for (short i = 0; i < arr.size(); i++)
        {
            sum += arr[i];                          // Update the prefix sum
            
            // If the 'sum' matches with i * (i + 1) / 2, then additional partition can be made
            // Whenever the prefix sum is equal to i * (i + 1) / 2, 
            // it means that upto 0 to i values can be sorted in ascending order. 
            // Example of 0 to 5: 0 + 1 + 2 + 3 + 4 + 5 = 5 * (5 + 1) / 2.
            if (sum == (i * (i + 1)) / 2) ans++;    
        }

        return ans;
    }
};

/*
Solution reference: Leetcode discussions
*/
