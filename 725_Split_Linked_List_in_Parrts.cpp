2024 Sept 8
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> ans({});
        ListNode* temp = head;
        ListNode* prev = nullptr;

        int size = 0;
        // Find the number of nodes in List
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        temp = head;
        // Case of when the splitting size is greater than the total number of nodes
        if (k >= size)
        {
            for (int i = 0; i < k; i++)
            {
                if (temp)
                {
                    prev = temp;
                    ans.emplace_back(prev);
                    temp = temp->next;
                    prev->next = nullptr;
                }
                else ans.emplace_back(nullptr);
            }
            return ans;
        }
        
        int a = size / k;  // Number of minimum nodes to place in each List 
        int b = size % k;  // Number of leftover nodes after assigning minimum number of nodes to each List
        int c = 1;         // Indicator of leftover. If there are leftover, c = 1. Else, c = 0.

        if (b == 0) c = 0;

        for (int i = 0; i < k; i++)
        {
            prev = temp;
            ans.emplace_back(prev);

            // Place extra value (total of a + 1 nodes )to first b Lists. Then place a nodes to remaining Lists
            for (int i = 0; i < a + c; i++)
            {  
                if (prev && i < a + c - 1) prev = prev->next;
                if (temp && i < a + c) temp = temp->next;     
            }
            if (prev && prev->next) prev->next = nullptr;

            // If all leftover nodes are assigned, set c = 0.
            b--;
            if (b == 0) c = 0;
        }

        return ans;
    }
};
