// 2025 Sept 5
class Solution {
public:
    int findClosest(int x, int y, int z) 
    {
        if (x < y)  // when x is located lower than y
        {
            if (z - x == y - z) return 0;
            else return z - x < y - z ? 1 : 2; 
        }
        else if (x > y) // when y is located lower than x
        {
            if (z - y == x - z) return 0;
            else return z - y < x - z ? 2 : 1; 
        }
        else return 0;  // when x and y are located together
    }
};
