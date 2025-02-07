// 2025 Feb 7

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        unordered_map<int, int> cmap;   // stores the frequency of each color
        unordered_map<int, int> bmap;   // maps a ball to a color 
        vector<int> ans;                // stores number of distinct colors at each query iteration

        for (auto& q : queries)
        {
            int ball = q[0];    // the ball this query 'q' is holding
            int color = q[1];   // the color this query 'q' is holding

            // If this ball was already encountered...
            if (bmap[ball])
            {
                // We are recoloring this ball. 
                // The color that this ball is originally painted has to be removed.
                int prevCol = bmap[ball];                       
                cmap[prevCol]--;    

                // If there are no more balls with this color, remove it from the 'cmap'
                if (cmap[prevCol] == 0) cmap.erase(prevCol);    
            }
            bmap[ball] = color; // coloring this ball with 'color' 
            cmap[color]++;      // record the frequency of this 'color'

            ans.push_back(cmap.size()); // record the number of distinct colors present after the query iteration
        }

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/editorial
*/
