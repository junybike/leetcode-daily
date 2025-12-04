// 2024 Oct 13

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        // Each MinHeap block conatins (value, list index, value index)
        // value        : the smallest value in a vector in nums
        // list index   : the index of vector in nums
        // value index  : the index of value in the list
        // The order of elements stored in MinHeap is the value from greatest to lowest
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Keeping track of largest value among all values
        int temp_max = INT_MIN;  

        // MinHeap initialization
        // Assign smallest values from each vectors in nums and other attributes
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push({nums[i][0], i, 0});
            temp_max = max(temp_max, nums[i][0]); // Update largest value
        }
        vector<int> small_range = {0, INT_MAX};   // Keeping track of minimum range

        while (!minHeap.empty())
        {
            vector<int> temp = minHeap.top();   // The minimum element in MinHeap
            minHeap.pop();

            // Elements in temp
            int temp_min = temp[0];
            int list_index = temp[1];
            int element_index = temp[2];

            // Check if the range of temp_max - temp_min is lower than current smallest range.
            // If lower, update the smallest range
            if ((temp_max - temp_min < small_range[1] - small_range[0]) ||
                (temp_max - temp_min == small_range[1] - small_range[0] && temp_min < small_range[0]))
                {
                    small_range[0] = temp_min;
                    small_range[1] = temp_max;
                }

            // Grab the next smallest value and other details from the vector where the
            // minimum element in MinHeap (temp) has just popped,
            // if there are still more values left to traverse in the vector
            if (element_index + 1 < nums[list_index].size())
            {
                int next_value = nums[list_index][element_index + 1];
                minHeap.push({next_value, list_index, element_index + 1});
                temp_max = max(temp_max, next_value);   // Update largest value
            }
            else
            {
                // Reached to the end of its vector
                break;
            }
        }
        return small_range;
    }
};

/*
solution reference
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/solutions/5905062/straight-forward-heap-priority-queue-solution-w-example-walkthrough-python-java-c
*/
