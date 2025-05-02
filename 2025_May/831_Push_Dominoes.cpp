// 2025 May 2

class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n = dominoes.length();
        string left2right = dominoes;   // tracks of result of domino when only pushed R dominoes
        string right2left = dominoes;   // tracks of result of domino when only pushed L dominoes

        int powerL = 1;
        int powerR = 1;

        // tracks of strength of pushed domino or domino getting pushed by others from L and R
        queue<int> pL;  
        stack<int> pR;  

        for (int i = 1; i < n; i++)
        {
            if ((left2right[i - 1] == 'R' || left2right[i - 1] != 'L') && 
            left2right[i - 1] != '.' && left2right[i] == '.') 
            {
                left2right[i] = '0';    // indicate that this domino is pushed
                pL.push(powerL);        // rrecord strength
                powerL++;
            }
            else powerL = 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if ((right2left[i + 1] == 'L' || right2left[i + 1] != 'R') && 
            right2left[i + 1] != '.' && right2left[i] == '.') 
            {
                right2left[i] = '0';    // indicate that this domino is pushed
                pR.push(powerR);        // record strength
                powerR++;
            }
            else powerR = 1;
        }

        for (int i = 0; i < n; i++)
        {
            char fromL = left2right[i];
            char fromR = right2left[i];

            if (fromL == '0' && fromR == '0')   // case where this domino is pushed from L and R
            {
                int L = pL.front(); // strength from L to R
                int R = pR.top();   // strength from R to L
                pL.pop(); pR.pop();

                if (L > R) left2right[i] = 'L';         // if strength from L is larger, record it as L 
                else if (L < R) left2right[i] = 'R';    // if strength from R is larger, rrecord it as R
                else left2right[i] = '.';               // if strength are equal, record it as .
            }
            else if (fromL == '0' && fromR == '.')      // case where only pushed from L to R
            {
                left2right[i] = 'R';
                pL.pop();
            }
            else if (fromL == '.' && fromR == '0')      // case where only pushed from R to L 
            {
                left2right[i] = 'L';
                pR.pop();
            }
        }
        return left2right;
    }
};
