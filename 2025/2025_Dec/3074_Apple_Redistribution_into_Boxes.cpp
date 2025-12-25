// 2025 Dec 24
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) 
    {
        int total = 0;  // the total amount of apples
        int ans = 0;    // number of boxes used
        for (int i : apple) total += i;

        sort(capacity.begin(), capacity.end(), std::greater<int>());    // sort the capacity in descending order
        for (int i : capacity) 
        {
            if (total <= 0) break;  // fill the apples with largest boxes first.
            total -= i;
            ans++;
        }
        return ans;
    }
};
