// 2025 Mar 23

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);    // adjacency list with the cost (time)
        for (auto& road : roads)
        {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }    

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        vector<long long> sTime(n, LLONG_MAX);  // shortest time to each node
        vector<int> pathcnt(n, 0);              // number of ways to reach each node in shortest time

        sTime[0] = 0;
        pathcnt[0] = 1;
        minHeap.emplace(0, 0);

        while (!minHeap.empty())
        {
            long long curTime = minHeap.top().first;    // current shortest time for the current node 'curNode' 
            int curNode = minHeap.top().second;
            minHeap.pop();

            if (curTime > sTime[curNode]) continue;             // skip the time that is longer than current shortest time
            for (auto & [adjNode, roadTime] : graph[curNode])   // to find shortest path 
            {
                if (curTime + roadTime < sTime[adjNode])        // found a shorter path for this node
                {
                    sTime[adjNode] = curTime + roadTime;        // update the shortest time
                    pathcnt[adjNode] = pathcnt[curNode];        // resets the path count
                    minHeap.emplace(sTime[adjNode], adjNode);   // insert the shortest time and the adj node to minHeap
                }
                else if (curTime + roadTime == sTime[adjNode])  // another way to reach the node with current shortest time 
                {
                    pathcnt[adjNode] = (pathcnt[adjNode] + pathcnt[curNode]) % MOD; // add to the path count
                }
            }
        }

        return pathcnt[n - 1];
    }
};
/*
solution reference
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/editorial
*/
