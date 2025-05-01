// 2025 May 1
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(tasks.begin(), tasks.end());       // sorts task in ascending order
        sort(workers.begin(), workers.end());   // sorts workers in ascending order

        int t_len = tasks.size();
        int w_len = workers.size();
        int ans = 0;

        // check if M tasks can be done
        auto check = [&](int M) -> bool  
        {
            multiset<int> w_set;
            int p = pills;

            // Insert (w_len - M) to w_len workers in multiset w_set
            for (int i = w_len - M; i < w_len; i++)
            {
                w_set.insert(workers[i]);
            }
            for (int i = M - 1; i >= 0; i--)
            {
                // check if the worker at the end of w_set can do the task
                if (auto it = prev(w_set.end()); *it >= tasks[i]) w_set.erase(it);
                else
                {   // check if worker with a pill can do the task
                    if (!p) return false;
                    auto val = w_set.lower_bound(tasks[i] - strength);

                    if (val == w_set.end()) return false;
                    w_set.erase(val);
                    p--;
                }
            }
            return true;
        };

        int L = 1;
        int R = min(t_len, w_len);

        // binary search to find the maximum number of tasks can be completed
        while (L <= R)
        {
            int M = (L + R) / 2;
            if (check(M))
            {
                ans = M;
                L = M + 1;
            }
            else R = M - 1;
        }

        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/editorial
*/
