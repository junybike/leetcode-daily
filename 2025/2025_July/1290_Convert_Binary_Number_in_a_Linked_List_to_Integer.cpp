// 2025 July 15
class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        stack<bool> bits;
        while (head)  // get all bits from linked list
        {
            bits.push(head->val);
            head = head->next;
        }

        int i = 0;
        int ans = 0;
        while (!bits.empty())  // calculate the number with the bits
        {
            if (bits.top()) ans += 1 << i;
            bits.pop();
            i++;
        }
        return ans;
    }
};
