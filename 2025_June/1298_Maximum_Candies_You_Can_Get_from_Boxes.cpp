// 2025 June 3

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        queue<int> q;               // to store boxes 
        for (int i : initialBoxes)  // get all boxes that I already have 
        {
            q.push(i);
        }    

        vector<bool> visited(candies.size(), 0);    // keep track of which boxes I took candy from already
        queue<int> q_tmp = q;                       // used to determine when to stop the infinite loop 

        int ans = 0;

        while (!q.empty())
        {
            int curBox = q.front(); // current box
            q.pop();

            if (status[curBox] && !visited[curBox]) // check if this box is opened and hasn't taken candy from yet
            {
                for (int i : keys[curBox])  // update status for any new keys I found
                {
                    status[i] = 1;
                }
                for (int i : containedBoxes[curBox])    // get more boxes
                {
                    q.push(i);
                }
                ans += candies[curBox]; // take the candies from the box and sum it to 'ans'
                visited[curBox] = true; // update visited vector
            }
            else q.push(curBox);    // put the box back into the queue if this box is locked

            if (q_tmp == q) break;  // to break infinite loop (check if queue hasnt changed)
            q_tmp = q;
        }
        return ans;
    }
};
