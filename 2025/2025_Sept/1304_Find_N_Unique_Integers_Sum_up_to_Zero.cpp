// 2025 Sept 7
class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> ans;
        for (int i = n / 2; i >= -n / 2; i--) // inserting [-n/2, n/2]  
        {
            // if even, dont add zero to the vector.
            if (n % 2 == 0 && i == 0) continue;
            ans.push_back(i);
        }
        return ans;
    }
};
