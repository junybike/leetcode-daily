// 2025 Mar 8

class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int w_cnt = 0;                  // to keep the number of white blocks
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W') w_cnt++;
        }

        int least_w = w_cnt;            // to keep the minimum number of white blocks in a range of k
        for (int L = 1, R = k; R < blocks.length(); L++, R++)
        {
            if (blocks[L - 1] == 'W') w_cnt--;      // if previous first block of its range was white block, decrement 'w_cnt'
            if (blocks[R] == 'W') w_cnt++;          // if the next block is white block, increment 'w_cnt'
            if (w_cnt < least_w) least_w = w_cnt;   // if current 'w_cnt' is less than 'least_w', update 'least_w'
        }

        return least_w;
    }
};
