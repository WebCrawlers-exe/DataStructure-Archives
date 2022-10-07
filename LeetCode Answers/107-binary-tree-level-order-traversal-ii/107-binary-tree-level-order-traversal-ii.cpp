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
    
//     Inserting NULL after each level in tree. Whenever we encounter NULL insert another NULL.
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> op;
        if(root==NULL)
            return op;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        
        while(q.size()>1)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr==NULL)
            {
                q.push(NULL);
                op.push_back(v);
                v={};
            }
            else
            {
                v.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        op.push_back(v);
        reverse(op.begin(),op.end());
        return op;
    }
};