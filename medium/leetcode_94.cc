//94.binary-tree-inorder-traversal
//tag:traversal & recursion -> iteration
//many way to implement
//recursion & iteration 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //dfs(root, ans);
        inorderTraversal2(root);
        inorderTraversal3(root);
        return ans;
    }
    
    //recursion - the easiest may.
    void dfs(TreeNode* root,vector<int> &List){
        if(root==nullptr)
            return ;
        dfs(root->left, List);
        List.push_back(root->val);
        dfs(root->right, List);
    }

    //iteration with bfs span written in 2019 
    //can be more neat with (k---TreeNode,v---Colored)
    //meaningless name but still interesting --2020/9/19
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> a;
        stack<pair<TreeNode*, int> > s;
        if(root==nullptr)
            return a;
        s.push(make_pair(root,0));
        pair<TreeNode*,int> tmp;
        while(!s.empty())
        {
            tmp=s.top();
            s.pop();
            if(tmp.first==nullptr)
            {
                a.push_back(tmp.second);
                continue;
            }
            
            if(tmp.first->right)
                s.push(make_pair(tmp.first->right,0));
            s.push(make_pair(nullptr,tmp.first->val));
            if(tmp.first->left)
                s.push(make_pair(tmp.first->left,0));
        }
        return a;
    }

    //iteration using stack by Leetcode official
    //neat but tricky
    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack_;
        TreeNode *top;
        while(root||!stack_.empty()){
            while(root!=nullptr){
                stack_.push(root);
                root=root->left;
            }

            top=stack_.top();
            stack_.pop();
            ans.push_back(top->val);    
            root=top->right;
        }
        return ans;
    }
};
