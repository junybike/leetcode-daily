// 2024 Sept 7

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution 
{
public:

    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if (root == nullptr) return false;      // TreeNode or the subtree is empty.

        // Check if there is a subtree that contains all values starting from
        // the root (starting point given in function), the left of root, the right of root)
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root)
    {
        if (head == nullptr) return 1;          // No more values in ListNode to compare. All values in ListNode exist.
        else if (root == nullptr) return 0;     // Reached to on of the ends of TreeNode. Did not find a subtree that contains all values in ListNode

        // If a value from ListNode and TreeNode matches, check left and right subtree of the TreeNode
        if (head->val == root->val) return dfs(head->next, root->left) || dfs(head->next, root->right);
        return 0;
    }
};

/*
The solution reference:
Lost :(
*/
