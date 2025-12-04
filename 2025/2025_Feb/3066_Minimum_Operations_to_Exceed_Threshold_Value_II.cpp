// 2025 Feb 13

class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        multiset<long long> m_set (nums.begin(), nums.end());   // convert 'nums' to multiset to keep values in ascending order
        int ops = 0;                                            // track number of operations done
        long long low = *m_set.begin();                         // track the lowest number in 'm_set'

        while (low < k)  // while the lowest number is still lower than a certain number k
        {
            auto v1 = m_set.begin();            // the location of first lowest element in 'm_set'
            auto v2 = next(m_set.begin(), 1);   // the location of second lowest element in 'm_set'

            m_set.insert(min(*v1, *v2) * 2 + max(*v1, *v2));    // insert min(x, y) * 2 + max(x, y) in 'm_set' where x and y are first two lowest elements in 'm_set'
            m_set.erase(v1, next(m_set.begin(), 2));            // erase the first two lowest elements from 'm_set'

            low = *m_set.begin();                               // update the lowest value in 'm_set'
            ops++;                                              // increment number of operations done
        }
        
        return ops;
    }
};
