// 2024 Sept 24

class Solution
{
public:

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
        // weight and distance synonyms

        // Set up node adjacency lists
        // A list contains: neighboring node and the index of the edge in edges list
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }

        // Store distances between each adjacent nodes
        // Initially, all distances are set to max integer. Except for source node.
        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        // First, change all weight of -1 to 1 and get a shortest path
        // Stores the distances in the first column of the distances array
        Dijkstra(adjacencyList, edges, distances, source, 0, 0);
        
        // If shortest path from source to destination is greater than target,
        // this case is not possible. Return empty array.
        int difference = target - distances[destination][0];
        if (difference < 0) return {};

        // Second, tries to modify the weight of -1 edges and find the shortest path
        // that matches the total distance of target.
        Dijkstra(adjacencyList, edges, distances, source, difference, 1);

        // If the new shortest path to destination is not equal to the target,
        // this case is not possible. Return empty array.
        if (distances[destination][1] < target) return {};

        // Set remaining weights of -1 to 1 
        for (auto& edge: edges)
        {
            if (edge[2] == -1) edge[2] = 1;
        }

        return edges;
    }

private:

    void Dijkstra(const vector<vector<pair<int, int>>>& adjacencyList, 
        vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run)
    {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty())
        {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue;

            for (auto& neighbor : adjacencyList[currentNode])
            {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];
                
                if (weight == -1) weight = 1;

                // This part runs only if the run is set to 1
                // Tries to increase the weight of -1 edges to make it equal to
                // target - sum of remaining distances to the destination
                if (run == 1 && edges[edgeIndex][2] == -1)
                {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];

                    if (newWeight > weight)
                    {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                // Compares the distance of "current node to next node" and modified weight
                // If unmodified is greater, apply the modified weight to the original weight.  
                if (distances[nextNode][run] > distances[currentNode][run] + weight)
                {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};

/*
The solution reference:
https://leetcode.com/problems/modify-graph-edge-weights/solutions/5708699/dijkstra-s-with-tc-o-e-v-log-v-beats-100-in-all-languages
*/
