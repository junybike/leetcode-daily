// 2025 July 22
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_map<int, int> umap;   // in a window, keep track of number of each values appeared in nums 
        int n = nums.size();
        int cnt = 0;            // sum of all values from index i to j 
        int ans = 0;            // max sum

        for (int i = 0, j = 0; j < n; j++)  // i = left index, j = right index
        {
            int cur = nums[j];
            umap[cur]++;

            if (umap[cur] > 1)  // if a value is appeared twice in a window, delete all values from index i until the repeated value is removed
            {
                while (umap[cur] > 1 && i < n)
                {
                    cnt -= nums[i];
                    umap[nums[i]]--;
                    i++;
                }
            }

            cnt += cur;
            if (ans < cnt) ans = cnt;   // update max sum
        }    

        return ans;
    }
};
