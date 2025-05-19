// 2025 May 19
class Solution {
public:
    string triangleType(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) return "none";    // check if forming a triangle is possible

        if (nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral"; // check if it is a equilateral 
        else if ((nums[0] == nums[1]) || (nums[1] == nums[2]) || (nums[0] == nums[2])) return "isosceles";  // check if it is a isosceles
        else return "scalene";  
    }
};
