// 2024 Oct 4

class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        sort(skill.begin(), skill.end());      // Sort the skill vector in ascending order
        long long ans = 0;                     // The value to return 
        int size = skill.size();               // The size of skill vector
        int prev = skill[0] + skill[size - 1]; // The optimal chemistry of a team (lowest skill + highest skill) 

        for (int i = 0; i < size / 2; i++)
        {   
            // If the next optimal chemistry of a team is not equal to the prev chemistry,
            // this case is impossible to form all teams with equal skill.
            if (ans != 0 && skill[i] + skill[size - i - 1] != prev) return -1;   
            
            // Add the multiple of two players skill to ans.
            ans += skill[i] * skill[size - i - 1];
        }

        return ans;
    }
};
