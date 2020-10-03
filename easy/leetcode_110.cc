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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return isBalanced(root->left) &&
        isBalanced(root->right) && 
        abs(height(root->left)-height(root->right))<=1;
    }
    int height(TreeNode* root){
        if(!root)
            return 0;//TO-DO: 0 OR -1
        return max(height(root->left),height(root->right))+1;
    }
};
