// 2024 Nov 12

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        int q_size = queries.size();    // the size of 'queries' vector
        vector<pair<int, int>> list;    // pair vector containing values in 'queries' vector and its position in the vector
        
        sort(items.begin(), items.end());   // sort the items in the increasing order of price
        
        // Set up the 'list' vector and sort the vector in the increasing order of query value
        for (int i = 0; i < q_size; i++)
        {
            list.push_back({queries[i], i});
        }
        sort(list.begin(), list.end());

        vector<int> ans(q_size);    // the vector to return. contains the maximum beauty of item for each queries.
        int best = 0;               // to keep track of the best beauty value for each iteration 
        int index = 0;              // to keep track of the index of value in 'item' vector

        for (auto i : list)
        {
            // If the current query budget value is greater or equal to the price of the 'item' at position 'index',
            // check if the current value of 'item' is greater than the 'best' beauty value. Update if so. 
            // Repeat until the index reaches to the end of 'items' or 'item''s price going upto the queries budget.
            while (index < items.size() && items[index][0] <= i.first)
            {
                if (best < items[index][1]) best = items[index][1];
                index++;
            }
            ans[i.second] = best;   // Assign the final best beauty value for the current query.
        }

        return ans;
    }
};

/*
Solution reference
https://leetcode.com/problems/most-beautiful-item-for-each-query/solutions/6035220/simple-and-short-working-12-11-2024
*/
