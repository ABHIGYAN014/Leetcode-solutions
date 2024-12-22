class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // An empty tree is symmetric
        return isMirror(root->left, root->right);
    }
    
private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true; // Both nodes are null
        if (!t1 || !t2) return false; // Only one node is null
        if (t1->val != t2->val) return false; // Values do not match
        
        // Check the symmetry of subtrees
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};
