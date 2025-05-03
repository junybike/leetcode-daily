// 2025 May 3

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        if (tops == bottoms) return 0;  // tops and bottoms are same

        // dominoes frequencies in tops and bottoms
        vector<pair<int, int>> freq = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
        vector<pair<int, int>> freq_bot = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
        
        // if is_bot[0] is true, there are more '1 domino' in bottoms 
        vector<bool> is_bot(6, false);
        int n = tops.size();

        // initialize freq and freq_bot
        for (int i = 0; i < n; i++)
        {
            freq[tops[i] - 1].second++;
            freq_bot[bottoms[i] - 1].second++;
        }

        // if a domino freq in 'freq_bot' is larger than 'freq', replace with the 'freq_bot' freq
        // and set is_bot[i - 1] true 
        for (int i = 0; i < 6; i++)
        {
            if (freq[i].second < freq_bot[i].second) 
            {
                freq[i].second = freq_bot[i].second;
                is_bot[i] = true;
            }
        }

        // sort based on the freq 
        sort(freq.begin(), freq.end(), [](auto &left, auto &right) 
        {
            return left.second > right.second;
        });

        for (auto& pair : freq)
        {
            int target = pair.first;
            int cnt = 0;

            // if is_bot is true for this domino, check if the domino in bottoms can be replaced from tops
            if (is_bot[target - 1])
            {
                for (int i = 0; i < n; i++)
                {
                    if (bottoms[i] != target && tops[i] == target) cnt++;
                    else if (bottoms[i] != target && tops[i] != target) break;
                }
                if (n - cnt == pair.second) return cnt;     // check if the dominoes are all matched
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (tops[i] != target && bottoms[i] == target) cnt++;
                    else if (bottoms[i] != target && tops[i] != target) break;
                }
                if (n - cnt == pair.second) return cnt;
            }
        }
        return -1;
    }
};
