class Solution {
public:

    // Possible swapping options for "0". For example, if "0" is at index 0, position can be swapped with 1 or 3.
    vector<vector<int>> direction = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}}; 

    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string target = "123450";   // The goal for "start" string
        string start = "";          // To hold the current "board" in string format

        // Set "start" 
        for (auto& row : board)
        {
            for (char c : row)
            {
                start += c + '0';
            }
        }
        if (start == target) return 0;  // If "start" is already the same as "target", no movement required. Return 0.

        set<string> vis;    // Keep track of visited configuration
        queue<string> q;    // To store various board in string format (swapped position of "0", "start", etc)

        q.push(start);      // Push the first board ("start")
        vis.insert(start);  // Keep track of kinds of board encountered during BFS
        int step = 0;       // Keep track of number of swaps

        // BFS
        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                string cur = q.front();     // Get a board in string format
                q.pop();

                if (cur == target) return step; // Return the "step" if a board is same as "target"
                int pos = cur.find('0');        // Find the position of the "0"

                // Generating swapped position boards with available options with the current position of "0".
                for (auto& arr : direction[pos])
                {
                    // Get a copy of board with a swapped positioned "0" from the current string 'cur'.
                    string next = cur;
                    swap(next[arr], next[pos]);

                    // If the board "next" hasn't been seen so far, record this to prevent from encountering this later in future again.
                    if (!vis.count(next))
                    {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        // Case where no possible solution found
        return -1;
    }
};

/*
solution reference
https://leetcode.com/problems/sliding-puzzle/solutions/6080641/simple-bfs-solution-beats-100-breadth-first-search-c-java-python-javascript
*/
