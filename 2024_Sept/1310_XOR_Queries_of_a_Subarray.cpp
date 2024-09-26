// 2024 Sept 13

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        for (vector<int> pair : queries)
        {
            int insert = arr[pair[0]];  // starting value 
            for (int i = pair[0] + 1; i <= pair[1]; i++)
            {
                insert = insert ^ arr[i];  // XOR the next value. Store in 'insert'
            }
            ans.push_back(insert);
        } 
        return ans;    
    }
};
