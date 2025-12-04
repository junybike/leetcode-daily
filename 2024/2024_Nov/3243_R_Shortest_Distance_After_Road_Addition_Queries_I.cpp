// 2024 Nov 27

class Solution {
public:

    vector<int> dijkstra(int n, vector<vector<int>>& road, int a)
    {
        set<pair<int, int>> sp;     // To store the road and bridge which contains their starting pos and destination
        vector<int> dist(n, 1e9);   // To store the distance of road and bridge

        sp.insert({0, a});  // Insert the starting position 0.
        dist[a] = 0;        // Set the distance of first sp value 0.

        while (!sp.empty())
        {
            int dest = sp.begin()->second;  // The destination of the first road or bridge at sp
            int d = sp.begin()->first;      // The distance from the starting position to the destination.
            sp.erase(sp.begin());           // Pop the first value.

            // Iterate through all destinations from the starting position = dest 
            for (int adj : road[dest])
            {
                // If the distance in 'adj' has a shorter distance to the destination (a shortcut)
                // than some distance 'adj', erase the existing path with distance 'adj' from the 'sp'
                // and insert a new path with distance 'd'.
                if (d + 1 < dist[adj])
                {
                    if (dist[adj] != 1e9) sp.erase({dist[adj], adj});
                    dist[adj] = d + 1;
                    sp.insert({dist[adj], adj});
                }
            }
        }
        return dist;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> ans;                // To store the shortest distances 
        vector<vector<int>> road(n);    // To store the paths from one place to another

        // Set 'road' vector by assigning default destination position
        for (int i = 0; i < n - 1; i++)
        {
            road[i].push_back(i + 1);
        }

        for (auto& arr : queries)
        {
            // Assign the bridge by assigning its destination to starting position index in road
            // to indicate that at that starting position, there is another way available.
            road[arr[0]].push_back(arr[1]);  
           
            // Run dijkstra to get a list of distances from possible paths
            auto bridge = dijkstra(n, road, 0);

            // The last value in 'bridge' contains the shortest path possible with the current roads and bridges.
            // Store the shortest path to the 'ans' vector.
            ans.push_back(bridge[n - 1]);
        }

        return ans;    
    }
};

/*
solution reference
https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/solutions/5583268/c-easy-to-understand-code-dijkstra-algo
*/
