// 2025 June 24
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<int> keys;       // stores index of keys
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == key) keys.push_back(i);  // find indexes for keys
        }

        unordered_map<int, bool> indices;   // to indicate keys that are added to 'ans'
        vector<int> ans;                    // k distant indicies
        
        for (int i : keys) 
        {
            int L = max(0, i - k);      // find the lowest index it can reach from this index
            int R = min(n - 1, i + k);  // find the highest index it can reach from this index

            for (int j = L; j <= R; j++)
            {
                if (!indices[j])    // add the distant indice to ans 
                {
                    ans.push_back(j);
                    indices[j] = true;
                }
            }
        }
        return ans;
    }
};
