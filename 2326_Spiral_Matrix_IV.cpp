/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<int> array(n,-1);
        vector<vector<int>> ans(m,array);
        ListNode* temp = head;

        int i = 0, j = 0;   // index n, m
        int top = 0, bot = m - 1, left = 0, rig = n - 1;  // Boundaries for 4 sides
        int opt = 0;   // Direction option

        if (n == 1) opt = 1;  // Case where the matrix is a 1D vertical matrix

        while (temp)
        {
            ans[j][i] = temp->val;
            temp = temp->next;

            // After reaching to the boundary, 
            // decrease the appropriate boundary and update the next direction
            switch (opt)
            {
                // Heading left
                case 0:
                    
                    i++;
                    if (i == rig)
                    {
                        opt = 1;
                        top++;
                    }
                    break;
                // Heading down
                case 1:

                    j++;
                    if (j == bot)
                    {
                        opt = 2;
                        rig--;
                    }
                    break;

                // Heading left
                case 2:

                    i--;
                    if (i == left)
                    {
                        opt = 3;
                        bot--;
                    }
                    break;

                // Heading up
                case 3:

                    j--;
                    if (j == top)
                    {
                        opt = 0;
                        left++;
                    }
                    break;
            }
        }

        return ans;
    }
};
