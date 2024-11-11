// 2024 Nov 11

class Solution {
public:

    // Returns a bool vector of size n. At ith position, it is set to true if i is a prime number 
    // *This function is from GFG.
    vector<bool> sieve(int n) 
    {
        // Create a vector of n elements with all
        // elements true
        vector<bool> primes(n + 1, true);

        // Since 0 and 1 is not prime, mark them false
        primes[0] = primes[1] = false;

        // Mark all the multiples of numbers from
        // 2 to sqrt(n) as false
        for (int i = 2; i * i <= n; i++) 
        {
            if (primes[i]) 
            {
                for (int j = i * i; j <= n; j += i)
                {   
                    primes[j] = false;
                }
            }
        }
        
        // Return the vector that contains all the
        // prime numbers
        return primes;
    }

    bool primeSubOperation(vector<int>& nums) 
    {
        // Prime number location. At ith position, it is set to true if i is a prime number. 
        vector<bool> primes = sieve(1000);

        // Iterate through the 'nums' vector backwards
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // If the value is less than the value in front, continue. It is in order.
            if (nums[i] < nums[i + 1]) continue;
            else
            {
                // Determine the difference between the value and the value in front.
                int diff = nums[i] - nums[i + 1];

                // Iterate through the prime number list. Find the first larger (prime) number than the 'diff'. 
                for (int p = 0; i < 1000; p++)
                {
                    if (p > diff && primes[p]) 
                    {
                        nums[i] -= p;   // If found, subtract the prime number from the current value and stop the loop.
                        break;
                    }
                }

                // If the current value is still larger than the value in front, or the current value is 0 or less,
                // not possible to make the 'nums' in order. Return false.
                if (nums[i] >= nums[i + 1] || nums[i] <= 0) return false;
            }
        }
        return true;
    }
};
