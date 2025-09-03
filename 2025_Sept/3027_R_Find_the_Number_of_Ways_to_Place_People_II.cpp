// 2025 Sept 3
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        int ans = 0;

        // sorts points by x-coordinate in ascending order
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
             });

        for (int i = 0; i < points.size() - 1; i++)
        {
            auto& pointA = points[i];
            int xmin = pointA[0] - 1;
            int xmax = INT_MAX;
            int ymin = INT_MIN;
            int ymax = pointA[1] + 1;

            // for each pointA, check all points with greater x coordinates if they satisfy the condition
            // update xmin and ymin through checking
            for (int j = i + 1; j < points.size(); j++)
            {
                auto& pointB = points[j];

                if (pointB[0] > xmin && pointB[0] < xmax && pointB[1] > ymin && pointB[1] < ymax)
                {
                    ans++;
                    xmin = pointB[0];
                    ymin = pointB[1];
                }
            }
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/editorial
*/
