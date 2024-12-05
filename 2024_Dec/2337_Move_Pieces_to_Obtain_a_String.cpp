// 2024 Dec 5

class Solution {
public:
    bool canChange(string start, string target) 
    {
        vector<pair<int, char>> s_pair; // Stores pairs that contains index of L and R in 'start'
        vector<pair<int, char>> t_pair; // Stores pairs that conatins index of L and R in 'target'

        // Find all L and R in 'start' and 'target' and store their locations in 's_pair' and 't_pair'
        for (int i = 0; i < start.length(); i++)
        {
            if (start[i] != '_') s_pair.push_back({i, start[i]});
            if (target[i] != '_') t_pair.push_back({i, target[i]});
        }

        // Case when 'start' and 'target' has different number of L/R
        if (s_pair.size() != t_pair.size()) return false;

        // For each L/R starting from the beginning of 'start', check if L/R can be moved to match to the next L/R in target.
        for (int i = 0; i < s_pair.size(); i++)
        {
            // If the current characters at s_pair and t_pair are not the same, 
            // then character from s_pair will get blocked by other type of character when trying to move.
            if (s_pair[i].second != t_pair[i].second) return false;

            // If the current character located is located more right than the next target character to match and the character to move is R,
            // then the characters cannot be matched. R must travel left to match the characters, but only allowed to move right.
            if (s_pair[i].first > t_pair[i].first && s_pair[i].second == 'R') return false;

            // If the current character located is located more left than the next target character to match and the character to move is L,
            // then the characters cannot be matched. L must travel right to match the characters, but only allowed to move right.
            if (s_pair[i].first < t_pair[i].first && s_pair[i].second == 'L') return false;
        }

        return true;
    }
};
