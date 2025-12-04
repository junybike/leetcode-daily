// 2025 Sept 1
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        auto calc = [](int passes, int total)
        {
            return (double)(passes + 1) / (total + 1) - (double)passes / total;
        };

        // contains the ratio for each classes from highest to lowest
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& c : classes)
        {
            maxHeap.push({calc(c[0], c[1]), {c[0], c[1]}});
        }

        // add extra students to classes with highest ratio 
        while (extraStudents--)
        {
            auto [cur, info] = maxHeap.top();
            maxHeap.pop();

            int passes = info.first;
            int total = info.second;

            maxHeap.push({calc(passes + 1, total + 1), {passes + 1, total + 1}});
        }

        // sum up all the ratio to get the total
        double ratio = 0;
        while (!maxHeap.empty())
        {
            auto [_, info] = maxHeap.top();
            maxHeap.pop();
            ratio += (double)info.first / info.second;
        }

        return ratio / classes.size();
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-average-pass-ratio/editorial
*/
