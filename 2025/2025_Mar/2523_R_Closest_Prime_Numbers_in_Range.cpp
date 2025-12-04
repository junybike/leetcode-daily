// 2025 Mar 7

class Solution {
public:

    // Determine if value n is a prime number
    bool isPrime(int n)
    {
        if (n == 1) return false;
        for (int i = 2; i <= n/2; ++i) 
        {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) 
    {
        vector<int> ans (2, 0); // The two prime numbers to return
        vector<int> primes;     // To hold all prime numbers in between 'left' and 'right'

        for (int i = left; i <= right; i++)
        {
            if (i % 2 == 0 && i > 2) continue;  // Skip even numbers greater than 2
            if (isPrime(i))
            {
                // If the difference between the two adjacent prime numbers are less than 2, return immediately
                if (!primes.empty() && i <= primes.back() + 2)   
                {
                    return {primes.back(), i};
                }
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) return {-1, -1}; // If there are less than 2 prime numbers, return {-1, -1}.
        
        // Find the two adjacent prime numbers with least difference
        int mindiff = INT_MAX;
        for (int i = 1; i < primes.size(); i++)
        {
            if (mindiff > primes[i] - primes[i - 1])
            {
                mindiff = primes[i] - primes[i - 1];
                ans[0] = primes[i - 1];
                ans[1] = primes[i];
            }
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/closest-prime-numbers-in-range/editorial
*/
