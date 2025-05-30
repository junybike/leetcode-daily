// 2025 May 30

class Solution {
public:

    void bfs(int startNode, vector<int>& edges, vector<int>& dist)
    {
        int n = edges.size();
        queue<int> q;               // keep track of nodes to be checked
        q.push(startNode);

        vector<bool> visited(n);    // keep track of which node is visited
        dist[startNode] = 0;        // startNode to startNode distance is 0

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (visited[node]) continue;
            visited[node] = true;

            int adj = edges[node];              // the current node's adj node 
            if (adj != -1 && !visited[adj])     // check if adj node is visited 
            {
                dist[adj] = 1 + dist[node];     // sum up the distance
                q.push(adj);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);      // shortest distances from node 1 to every nodes
        vector<int> dist2(n, INT_MAX);      // shortest distances from node 2 to every nodes
        
        bfs(node1, edges, dist1);   // bfs to fill dist1
        bfs(node2, edges, dist2);   // bfs to fill dist2

        int minDistNode = -1;       // the node to return 
        int minDistCur = INT_MAX;   // max between distances from node 1 to minDistNode and from node 2 to minDistNode

        for (int i = 0; i < n; i++) // finding the min max distance
        {
            if (minDistCur > max(dist1[i], dist2[i]))
            {
                minDistNode = i;
                minDistCur = max(dist1[i], dist2[i]);
            }
        }

        return minDistNode;    
    }
};

/*
solution reference
https://leetcode.com/problems/find-closest-node-to-given-two-nodes/editorial
*/
