// 2024 Dec 16

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        // Keep track of lowest value with the index in nums
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;   
        int n = nums.size();    // Size of 'nums'

        // Initializing the 'pq'
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});  
        }

        // 'k' updates
        for (int i = 0; i < k; i++)
        {
            pair temp = pq.top();           // Get the lowest value and its index in 'nums'
            temp.first *= multiplier;       // Update the value
            nums[temp.second] = temp.first; // Update the value in 'nums'
            
            pq.pop();                       // Remove the top value in 'pq'
            pq.push(temp);                  // Insert the updated value in 'pq'
        }
        return nums;
    }
};
