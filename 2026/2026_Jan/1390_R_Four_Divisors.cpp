// 2025 Jan 4
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        int ans = 0;    // sum of all divisors
        set<int> divs;  // to store divisors of a number

        for (int it : nums)
        {
            int curr = it + 1;  // case for dividing n with 1

            for (int i = 2; i <= sqrt(it); i++)
            {
                // if the number is divisible by i and divs have less than 3, insert the pair of divisors
                // else if the number already has 3 or more divisors and found a pair of divisor, move onto next number
                if (divs.size() < 3 && !(it % i))   
                {
                    divs.insert(i);
                    divs.insert(it / i);
                }
                else if (it % i == 0 && divs.size() >= 3) break;    
            }
            if (divs.size() == 2) // 4 divisors found: n, 1, and a pair in divs
            {
                ans += curr;
                for(int it : divs) ans += it;
            }
            divs.clear();   // clear the divs for next number
        }
        return ans;
    }
};

// solution reference: leetcode discussion tab
