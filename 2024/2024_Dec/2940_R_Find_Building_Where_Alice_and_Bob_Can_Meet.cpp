// 2024 Dec 22

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) 
    {
        int hn = heights.size();        // Size of 'heights'
        int qn = queries.size();        // Size of 'queries'
        vector<int> ans(qn, -1);        // To store the meeting place for each query in 'queries'. Initialize all with -1.
        vector<pair<int, int>> index;   // To store queries[i][1] and its index in 'queries'

        // Sets all queries[i][0] to be less than queries[i][1]
        for (int i = 0; i < qn; i++)
        {
            int& x = queries[i][0];     // Alice location
            int& y = queries[i][1];     // Bob location

            // If queries[i][0] is larger, swap their addresses (values)
            if (x > y) swap(x, y);                                  
            
            // Set the meeting place as queries[i][1] if the two locations are already the same or
            // Alice's location height is taller than Bob's location. 
            if (x == y || heights[x] < heights[y]) ans[i] = y;      
            
            // Store the pair of queries[i][1] and its index in 'queries' to 'index'
            else index.emplace_back(y, i);
        }

        sort(index.begin(), index.end(), greater<>());  // Sort the 'index' in descending order of the 'queries[i][1]' value.
        vector<pair<int, int>> st;                      // To store pairs of Alice's location and its index in 'queries' to compute meeting location
        int j = hn - 1;                                

        // For each Alice's location index that hasn't found a meeting place,
        for (auto [_, i] : index)
        {
            int x = queries[i][0];  // Alice location
            int y = queries[i][1];  // Bob location

            // Traverse all index in 'heights' that is greater than Bob location
            for ( ; j > y; j--)
            {
                // Pop all heights that is lower than height at 'j' 
                // Add pairs that are not lower than height at 'j'
                while (!st.empty() && heights[st.back().second] < heights[j]) st.pop_back();    
                st.emplace_back(heights[j], j);
            }

            // To verify that the place is leftmost building to meet.
            // Assign the height if verified. If not, assign -1.
            auto p = upper_bound(st.rbegin(), st.rend(), make_pair(heights[x], hn));
            ans[i] = (p == st.rend()) ? -1 : p->second;
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/solutions/6172579/sort-monotonic-stack-binary-search-51ms-beats-98-73
*/
