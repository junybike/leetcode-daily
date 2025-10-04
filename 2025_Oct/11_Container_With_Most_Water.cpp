// 2025 Oct 4

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int i = 0;
        int j = n - 1;

        int cur = 0;
        int ans = 0;
        while (i < j)
        {
            int cur = min(height[i], height[j]) * (j - i);  // current area of water
            ans = max(cur, ans);                            // update max area if current area is larger

            if (height[i] > height[j]) j--;                 // if left side is larger, shrink from right
            else i++;                                       // if right side is larger, shrink from left
        }
        return ans;
    }
};
