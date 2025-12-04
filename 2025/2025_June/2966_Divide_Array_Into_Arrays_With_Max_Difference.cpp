// 2025 June 18
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i += 3)
        {
            // check if the difference between 1st and 3rd are not larger than k
            if (nums[i + 2] - nums[i] > k) return {};               
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        
        return ans;    
    }
};
