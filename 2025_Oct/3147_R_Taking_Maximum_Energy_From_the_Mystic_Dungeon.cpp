// 2025 Oct 10
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) 
    {
        int n = energy.size();
        int ans = INT_MIN;

        for (int i = n - k; i < n; i++) // only start from wizards at 0 to n - k 
        {
            int sum = 0;

            for (int j = i; j >= 0; j -= k) // sum up energy from the back 
            {
                sum += energy[j];
                ans = max(ans, sum);    // keep update maximum energy as adding up
            }
            cout << sum << endl;
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/editorial
*/
