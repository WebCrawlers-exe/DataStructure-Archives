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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v1;
        queue<TreeNode*> q;
        if(root==NULL)
            return v1;
        q.push(root);
        q.push(NULL);
        vector<int> v2;
        while(q.size()>1)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr==NULL)
            {
                v1.push_back(v2);
                q.push(NULL);
                v2={};
            }
            else
            {
                v2.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            
        }
        v1.push_back(v2);
        return v1;
    }
};