// 2025 Aug 5
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int cnt = 0;
        for (int f : fruits)
        {
            bool unplaced = true;   // remains true if the current fruit cant find an available basket
            for (auto& b : baskets) // finding leftmost available baskets for the current fruit
            {
                if (f <= b) 
                {
                    b = -1;
                    unplaced = false;
                    break;
                }
            }
            if (unplaced) cnt++;
        }
        return cnt;
    }
};
