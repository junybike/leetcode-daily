// 2025 July 13

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        // sort both players and trainers vector
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int cnt = 0;    // number of players that can be trained
        int i = 0;      // to iterate players vector
        int j = 0;      // to iterate trainers vector

        while (j != trainers.size() && i != players.size())
        {
            if (players[i] <= trainers[j])  //
            {
                cnt++;
                i++;
            }           
            j++;
        }    
        return cnt;
    }
};
