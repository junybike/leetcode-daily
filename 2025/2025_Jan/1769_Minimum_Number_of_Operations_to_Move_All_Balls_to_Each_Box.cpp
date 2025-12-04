// 2025 Jan 6

class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.length(); // the amount of box in 'boxes'
        vector<int> ans;        // record each operations needed for each position

        for (int i = 0; i < n; i++)
        {
            int op = 0; // counting the operations needed for 'i' position
            for (int j = 0; j < n; j++)
            {
                // the distance from position 'i' to current position 'j' determines the amount of operations needed to move the ball from 'j' to 'i'.
                // add the operation needed to 'op'
                op += abs(i - j) * (boxes[j] == '1');
            }
            ans.push_back(op);
        }
        return ans;
    }
};

class RSolution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.length();     // the amount of box in 'boxes'
        vector<int> ans(n, 0);      // record each operations needed for each position
        vector<int> ball;           // holds the location of balls in 'boxes'

        // Find location of balls in 'boxes' and find the operation needed for first box in 'boxes'
        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1') 
            {
                ball.push_back(i);
                ans[0] += i;
            }
        }

        int bn = ball.size();   // the amount of balls in 'ball'
        int L = 0;              // an index in 'boxes' going left to right
        int R = bn;             // an index in 'boxes' going right to left

        for (int i = 1, j = 0; i < n; i++)
        {
            // if there are balls left to keep track and the next ball to encounter appears before the current box
            if (j < bn && i > ball[j])
            {
                // shrink the range between L and R and move on to the next ball
                L++;    
                R--;
                j++;
            }
            ans[i] = ans[i - 1] + L - R; // record the number of operations needed for current position
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/solutions/6236558/find-positions-of-1-prefix-sum-beats-100
*/
