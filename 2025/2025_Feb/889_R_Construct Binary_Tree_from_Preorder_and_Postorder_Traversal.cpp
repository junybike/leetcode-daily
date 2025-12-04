// 2025 Feb 23

// Index array solution
class Solution {
public:

    TreeNode* construct(int preStart, int preEnd, int postStart, vector<int>& preorder, vector<int>& post_order_index)
    {
        if (preStart > preEnd) return nullptr;                              // no more node to process.
        if (preStart == preEnd) return new TreeNode(preorder[preStart]);    // only one node left.

        int leftRoot = preorder[preStart + 1];                      // the left child root in preorder traversal
        int leftSize = post_order_index[leftRoot] - postStart + 1;  // the number of nodes in the left subtree

        // constructs left and right subtrees
        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = construct(preStart + 1, preStart + leftSize, postStart, preorder, post_order_index);
        root->right = construct(preStart + leftSize + 1, preEnd, postStart + leftSize, preorder, post_order_index);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int n = preorder.size();                // number of nodes
        vector<int> post_order_index(n + 1);    // index array of 'postorder'

        // Initializing 'post_order_index'
        for (int i = 0; i < n; i++)
        {
            post_order_index[postorder[i]] = i;
        }    
        return construct(0, n - 1, 0, preorder, post_order_index);
    }
};

// Recursion
class Solution2 {
public:

    TreeNode* construct(int& preIndex, int& postIndex, vector<int>& preorder, vector<int>& postorder)
    {
        TreeNode* root = new TreeNode(preorder[preIndex]);  // node with current preorder index 
        preIndex++;

        // constructs right and left subtree if the 'root' is not the last of its subtree
        if (root->val != postorder[postIndex]) root->left = construct(preIndex, postIndex, preorder, postorder);
        if (root->val != postorder[postIndex]) root->right = construct(preIndex, postIndex, preorder, postorder);
        postIndex++;

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int preIndex = 0;
        int postIndex = 0;
        return construct(preIndex, postIndex, preorder, postorder);
    }
};


/*
solution reference
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/editorial
*/
