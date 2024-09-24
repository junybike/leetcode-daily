// 2024 Sept 6

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

class Solution 
{
public:

    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_map<int, char> umap;  
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]] = 'a';
        }

        ListNode* temp = head;
        ListNode* ans = nullptr;
        ListNode* prev = nullptr;

        while (temp != nullptr)
        {
            // Case: when the value in node does not match any of values in 'nums' 
            // and the ans linked list is not empty
            if (umap[temp->val] != 'a' && ans != nullptr) 
            {
                prev->next = temp;
                prev = prev->next;
            }
            // Case: when the value in node does not match any of values in 'nums' 
            // and the ans linked list is empty
            else if (umap[temp->val] != 'a' && ans == nullptr)
            {              
                ans = temp;
                prev = ans;
            }
            temp = temp->next;
        }    
        prev->next = nullptr;

        return ans;
    }
};
