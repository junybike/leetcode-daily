// 2024 Dec 12

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int> pq;   // Priority queue to store the gifts in decreasing order of their value
        long long ans = 0;        // The total value of gifts remaining

        // For k iteration, takes the largest gift off from 'pq' and put their square rooted value back to 'pq' 
        for (int i = 0; i < k; i++)
        {
            int gift = pq.top();
            pq.pop();
            pq.push(sqrt(gift));
        }

        // Add up all the remaining gift's value in 'pq' to 'ans'
        long long ans = 0;
        while (!pq.empty()) 
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
