// 2025 Mar 29

class Solution {
public:

    const int MOD = 1e9 + 7;

    // power of a number but with MOD
    long long power(long long base, long long exp)
    {
        long long i = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1) i = ((i * base) % MOD);
            base = (base * base) % MOD;
            exp /= 2;
        }
        return i;
    }

    int maximumScore(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> primeScore(n);

        // Find prime score for each values in 'nums'
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for (int factor = 2; factor <= sqrt(num); factor++)
            {
                if (num % factor == 0)      // for each prime factor, increase primeScore
                {
                    primeScore[i]++;
                    while (num % factor == 0) num /= factor;
                }
            }
            if (num >= 2) primeScore[i]++;  // if the num is still greater or equal to 2, it is a prime factor
        }

        // to store the nearest elements with higher prime score on both sides of each number
        vector<int> nextDom(n, n);
        vector<int> prevDom(n, -1);

        stack<int> decPrimeScoreStack;  // stores monotonic decreasing prime score    

        for (int i = 0; i < n; i++)     // find next and prev dominant values for each number
        {
            while (!decPrimeScoreStack.empty() && primeScore[decPrimeScoreStack.top()] < primeScore[i])
            {
                int topIndex = decPrimeScoreStack.top();
                decPrimeScoreStack.pop();
                nextDom[topIndex] = i;      // keeps updating as long as current prime score is larger than stack's top 
            } 
            // if stack is not empty, sets prev dominant element for current index
            if (!decPrimeScoreStack.empty()) prevDom[i] = decPrimeScoreStack.top();
            decPrimeScoreStack.push(i);
        }

        vector<long long> cntSubarray(n);   // stores number of subarrays where each element is dominant
        for (int i = 0; i < n; i++)
        {
            cntSubarray[i] = (long long)(nextDom[i] - i) * (i - prevDom[i]);
        }

        priority_queue<pair<int, int>> processing;  // to process elements in decreasing order of their values
        for (int i = 0; i < n; i++)
        {
            processing.push({nums[i], i});
        }

        long long score = 1;
        while (k > 0)           // process elements while operations are left
        {
            auto [num, i] = processing.top();   // max value from queue
            processing.pop();

            long long op = min((long long)k, cntSubarray[i]);   // the number of operations 
            score = (score * power(num, op)) % MOD;     // raise element to the power of operations and add to score
            k -= op;    // update remaining operations
        }
        return score;
    }
};
/*
solution reference
https://leetcode.com/problems/apply-operations-to-maximize-score/editorial
*/
