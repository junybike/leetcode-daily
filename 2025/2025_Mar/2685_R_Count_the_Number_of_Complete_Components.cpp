// 2025 Mar 22

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        // forms adj list
        vector<vector<int>> graph(n);
        for (auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false); // record if the node is visited
        int cnt = 0;                    // record the number of complete components

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> nodes;  // finds all nodes involved in current node's component
                queue<int> q;       // nodes to be processed

                q.push(i);          
                visited[i] = true;

                while(!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    nodes.push_back(cur);

                    // find the adj nodes of the current node
                    for (int node : graph[cur])
                    {
                        if (!visited[node])
                        {
                            q.push(node);
                            visited[node] = true;
                        }
                    }
                }

                // check if the current node's component is complete
                // if number of nodes in the component is same as its graph adj list, it is complete
                bool complete = true;
                for (int i : nodes)
                {
                    if (graph[i].size() != nodes.size() - 1)
                    {
                        complete = false;
                        break;
                    }
                }
                if (complete) cnt++;
            }
        }
        return cnt;
    }
};

/*
solution reference
https://leetcode.com/problems/count-the-number-of-complete-components/editorial
*/
