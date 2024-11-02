#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        findPaths(root, targetSum, currentPath, result);
        return result;
    }
    
private:
    void findPaths(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;
        
        // Add the current node's value to the path
        currentPath.push_back(node->val);
        
        // Check if it's a leaf node and if the path sum equals targetSum
        if (!node->left && !node->right && targetSum == node->val) {
            result.push_back(currentPath); // Add the path to the result
        } else {
            // Continue the search on the left and right children
            findPaths(node->left, targetSum - node->val, currentPath, result);
            findPaths(node->right, targetSum - node->val, currentPath, result);
        }
        
        // Backtrack: remove the current node from the path
        currentPath.pop_back();
    }
};
