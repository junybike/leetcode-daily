// 2024 Nov 30

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        // Stores the in/out times. 
        // If theres a pair that starts at time A, increment the value at key A. 
        // If theres a pair that ends at time A, decrement the value at key A.  
        unordered_map<int, int> inOutDegree; 
        unordered_map<int, vector<int>> adjList;    // For each starting time, store all matching end times from 'pairs' 
              
        // Set adjList and inOutDegree by visiting all pairs
        for (auto& arr : pairs)
        {
            adjList[arr[0]].push_back(arr[1]);
            inOutDegree[arr[0]]++;
            inOutDegree[arr[1]]--;
        }

        // Set the first node with a specific end time to be visited: The pair with inOutDegree value of 1 must be the 'start'. 
        // Possible to have multiple nodes with the specific end time.
        int start = pairs[0][0];
        for (auto& [in, out] : inOutDegree)
        {
            if (out == 1)
            {
                start = in;
                break;
            }
        }

        vector<int> path;   // To store the times (in an order end_i-1 == start_i) for pairs to form. 
        stack<int> st;      // To keep track of which pairs to visit by storing their starting time for each 'adjList' subarray. 
        st.push(start);

        while (!st.empty())
        {
            // Get the next list of pairs with corresponding start time stored at the top of 'st'.
            auto& adjnodes = adjList[st.top()];

            // If there are no values stored at this starting time, all pairs for this time are processed.
            // Store this time in 'path' and remove from the 'st'.
            if (adjnodes.empty())
            {
                path.push_back(st.top());
                st.pop();
            }
            // If there are more pairs to process at this starting time, 
            // push the next one to 'st'.
            // Remove the one pushed to the 'st' from the 'adjnodes'.
            else
            {
                int next = adjnodes.back();
                st.push(next);
                adjnodes.pop_back();
            }
        }

        vector<vector<int>> ans;    // The pairs to return
        int size = path.size();     // The size of 'path'
        ans.reserve(size - 1);      // Set the memory for ans.

        // Store the pairs to the 'ans' from 'path'.
        for (int i = size - 1; i > 0; i--)
        {
            ans.push_back({path[i], path[i - 1]});
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/valid-arrangement-of-pairs/solutions/6081701/beats-100
*/
