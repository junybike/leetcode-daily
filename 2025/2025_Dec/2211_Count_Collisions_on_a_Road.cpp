// 2025 Dec 4
class Solution {
public:
    int countCollisions(string directions) 
    {
        int n = directions.length();
        int L = 0; // index where leading L stops
        int R = n; // index where trailing R stops

        bool traverseL = true;
        bool traverseR = true;
        for (int i = 0; i < n; i++) // find where leading L stops and trailing R starts
        {
            if (directions[i] == 'L' && traverseL) L++;
            else traverseL = false;
            if (directions[n - 1 - i] == 'R' && traverseR) R--;
            else traverseR = false;
        }

        int ans = 0;
        for (int i = L; i < R; i++) // collided cars are non stationary cars that are non leading L and trailing R
        {
            if (directions[i] != 'S') ans++;
        }
        return ans;
    }
};
