// 2025 Jan 27

class Solution {
public:

    void bfs(int numCourses, vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>& adjList, vector<vector<bool>>& isPrereq)
    {
        // Visit each course and 
        for (int i = 0; i < numCourses; i++)
        {
            queue<int> q;   // to store any course that are prerequisite to course 'i'
            q.push(i);      // Initially, store 'i' in the queue

            while (!q.empty())
            {
                int node = q.front();   // The current course to process
                q.pop();

                // Bring the adjacency list for the current course
                for (auto& adj: adjList[node])
                {
                    // If a course in adjList for current course is not marked in isPrereq,
                    // mark it true and push the course to the queue to process it later
                    if (!isPrereq[i][adj])  
                    {
                        isPrereq[i][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        unordered_map<int, vector<int>> adjList;    // Stores courses that are directly prerequisites  
        for (auto& edge : prerequisites)            // Initializes the 'adjList'
        {
            adjList[edge[0]] = edge[1];
        }

        // To record courses that is prerequisites to another either directly or indirectly
        // Perform BFS to determine
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false)); 
        bfs(numCourses, prerequisites, adjList, isPrereq);

        // Record the result in 'ans'
        vector<bool> ans;
        for (auto& q: queries)
        {
            ans.push_back(isPrereq[q[0]][q[1]]);
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/course-schedule-iv/editorial
*/
