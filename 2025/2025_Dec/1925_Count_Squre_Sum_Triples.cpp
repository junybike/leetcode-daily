// 2025 Dec 8

class Solution {
public:
    int countTriples(int n) 
    {
        int cnt = 0;
        for (int i = 3; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                double val = i * i + j * j; // i = a, j = b 
                double root = sqrt(val);    // c

                // check if the sqrt(val) is an integer and does not exceed n
                if (root <= n && root == static_cast<long long>(root)) 
                {
                    cnt += 2; // each triple can have two possible triples: (a, b, c) and (b, a, c)
                }
                else if (root > n) break; 
            }
        }    
        return cnt;
    }
};
