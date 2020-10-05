//5532.even-odd-tree
//tag: BFS
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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool odd = 0;
        int pre=0;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(odd^(cur->val%2)){
                //beginning of the new layer
                odd=!odd;
            }
            else{
                //judge the status
                if((odd&&pre>=cur->val)||
                    (!odd&&pre<=cur->val))
                    return false;
            }
            pre=cur->val;

            int sum=0;
            //traverse with certification
            if(cur->left){
                sum=cur->val+cur->left->val;
                //return false when cur Node and cur->left Node have same odd/even.
                if(sum%2==0)
                    return false;
                q.push(cur->left);
            }
            if(cur->right){
                sum=cur->val+cur->right->val;
                if(sum%2==0)
                    return false;
                q.push(cur->right);
            }
        }
        return true;
    }
};
