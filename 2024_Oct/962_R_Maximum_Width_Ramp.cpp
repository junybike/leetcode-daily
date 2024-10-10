// 2024 Oct 10

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n = nums.size();    // size of nums
        int ans = 0;            // largest width
        
        // Stack to store the index. 
        // But do not contain index that holds a value that is 
        // greater than previously added index. 
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            // Add the index i if it holds a smaller value 
            // than previously added value.
            if (s.empty() || nums[s.top()] > nums[i]) s.push(i);
        }  

        // Traverse from the back of nums vector
        for (int i = n - 1; i >= 0; i--)
        {
            // Compare the value at nums[i] and nums[index at the top of stack].
            // If nums[i] is larger, pop the top of stack and 
            // check if (index i - index at the top) is larger than current largest,
            // and update the largest width if it is larger.
            while (!s.empty() && nums[s.top()] <= nums[i])
            {
                ans = max(ans, i - s.top());
                s.pop();
            }
            // As you go down the stack, 
            // the value that the index is holding increases.
        }

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-width-ramp/solutions/5893635/fastest-way-to-solve-maximum-width-ramp
*/
