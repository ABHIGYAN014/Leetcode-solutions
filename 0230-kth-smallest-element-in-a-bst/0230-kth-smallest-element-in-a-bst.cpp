class Solution {
public:

    void solve(TreeNode* root,vector<int>&ans,int k)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->left,ans,k);
        ans.push_back(root->val);
        solve(root->right,ans,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        solve(root,ans,k);
        return ans[k-1]; 
    }
};