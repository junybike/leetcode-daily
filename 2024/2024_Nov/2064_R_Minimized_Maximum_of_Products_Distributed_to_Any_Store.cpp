// 2024 Nov 14

class Solution {
public:
    
    // This function checks if every value in 'quantities' 
    // can distribute at most 'a' amount of product to all stores.
    bool check(int a, int n, vector<int>& quantities)
    {        
        // Represents the amount of stores that can receive at most 'a' product
        int sum = 0;     
        
        // Determines the amount of stores each type of 'quantities' can distribute when
        // they are being distributed by at most 'a' products 
        // (must distribute 'a' product to a store to distribute to another store)
        // and record those values by adding them to 'sum'.
        
        for (int i : quantities)
        {
            sum = sum + (i + a - 1) / a;
        }

        // Determine whether if all stores can receive at most 'a' products.  
        return sum > n;     
    }

    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int L = 1;          // Minimum possible amount of 'quantities' type 
        int R = 100000;     // Maximum possible amount of 'quantities' type
        int M = 0;          // Keeping track of the middle amount of L and R

        // Perform binary search to find the minimum max amount of products that can be distributed
        while (L < R)
        {
            M = (L + R) / 2;    // Computing the middle amount of L and R
            
            // If the products can be distributed at most 'M' to all stores, 
            // then increase the base minimum amount by setting it to 'L'.  
            // Else, reduce the range of search by setting it to 'R'.

            if (check(M, n, quantities)) L = M + 1;
            else R = M;
        }

        // In the end, when R reaches L or lower, L is the minimum and maximum amount of products can be distributed
        return L;
    }
};

/*
Solution reference
https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/solutions/6042520/binary-search-of-koko-type-16ms-beats-99-25
*/
