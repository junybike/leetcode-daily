// 2024 Oct 14

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        // Stores the value ceil(x / 3) whenever x is added to the 'ans' (line 12). 
        priority_queue<int> pq;
        // Sort the 'nums' vector in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        long long ans = 0;    // maximal score to return
        int n = nums.size();  // size of 'nums' vector
        int i = 0;            // index to traverse 'nums' vector
        int count = 0;        // to keep track of the number of sums

        while(count < k)
        {
            // If nums[i] exists and 
            // ('pq' is empty or top of 'pq' (largest value of 'pq') is smaller than ith largest value in 'nums',
            // add the ith largest value in 'nums' and store the ceil(nums[i] / 3) to the pq.
            // Move on to the i + 1 index for 'nums'.
            if (i < n && (pq.empty() || pq.top() < nums[i]))
            {
                ans += nums[i];
                pq.push(ceil(double(nums[i]) / 3));
                i++;
            }
            // else, add the largest value in 'pq' to 'ans', 
            // add the ceil(largest value / 3) to the 'pq',
            // and remove the largest value in 'pq'.
            else
            {
                int temp = pq.top();
                ans += temp;
                pq.pop();
                pq.push(ceil(double(temp) / 3));
            }
            count++;
        }
        return ans;    
    }
};
