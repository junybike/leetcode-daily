// 2025 July 27
class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int cnt = 0;
        bool hill = false;
        bool vall = false;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i]) hill = true;         // indicates that we're encountering a hill
            else if (nums[i - 1] > nums[i]) vall = true;    // indicates that we're encountering a downhill

            if (nums[i - 1] > nums[i] && hill) // when we go down when we were encountering a hill, it is a hill.
            {
                cnt++;
                hill = false;
            }
            else if (nums[i - 1] < nums[i] && vall) // when we go up when we were encountering a downhill, it is a valley
            {
                cnt++;
                vall = false;
            }
        }   
        return cnt; 
    }
};
