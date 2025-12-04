// 2024 Sept 10

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* temp = head;
        int i = 0;

        while (temp->next)
        {
            i = gcd(temp->val, temp->next->val);  // Calculate the greatest common divisor of the current and next node value
            ListNode* newnode = new ListNode(i, temp->next);  // insert the gcd in between the two node
            temp->next= newnode;
            temp = temp->next->next;
        }   

        return head;   
    }
};
