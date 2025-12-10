// 2025 Dec 11
class Solution {
public:
    int countPermutations(vector<int>& complexity) 
    {
        int n = complexity.size();
        int root = complexity[0];
        int cnt = 1;
        
        for (int i = 1; i < n; i++)
        {
            // add the total number of permutation possible if ith computer can be solved (excluding the root)
            // if there is a complexity greater or equal to root, return 0 since we can't solve all passwords
            if (root < complexity[i] && i > 1) cnt = static_cast<long long>(cnt) * i % (int)(1e9 + 7);
            else if (root >= complexity[i]) return 0;
        }    
        return cnt;
    }
};
