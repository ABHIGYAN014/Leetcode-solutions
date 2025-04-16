/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(vector<int>& ans, TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }
        solve(ans, root->left, k);
        ans.push_back(root->val);
        solve(ans, root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        solve(ans, root, k);
        int i = 0, j = ans.size() - 1;
        while (i < j) {
            if (ans[i] + ans[j] == k)
                return true;
            else if (ans[i] + ans[j] < k)
                i++;
            else
                j--;
        }

        return false;
    }
};