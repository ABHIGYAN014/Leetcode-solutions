class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return max(leftheight, rightheight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {  
            return true;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int diff = abs(leftheight - rightheight);

        bool balanced = (diff <= 1);

        bool leftbalanced = isBalanced(root->left);
        bool rightbalanced = isBalanced(root->right);

        return balanced && leftbalanced && rightbalanced;
    }
};
