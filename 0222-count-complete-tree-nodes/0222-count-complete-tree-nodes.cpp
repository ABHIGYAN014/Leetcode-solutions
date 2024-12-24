class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0; // Base case: empty tree
        return 1 + countNodes(root->left) + countNodes(root->right); // Count root, left subtree, and right subtree
    }
};
