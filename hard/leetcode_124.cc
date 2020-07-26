/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int tmp=INT_MIN;
        int ans=dfs(root,tmp);
        return max(ans,tmp);
    }
    
    int dfs(TreeNode* root,int &tmp_max)
    {
        if(root==nullptr)
            return 0;
        
        int l_max=max(0,dfs(root->left,tmp_max));
        int r_max=max(0,dfs(root->right,tmp_max));
        
        tmp_max=max(tmp_max,root->val+l_max+r_max);
        
        return root->val+max(l_max,r_max);
    }
};
