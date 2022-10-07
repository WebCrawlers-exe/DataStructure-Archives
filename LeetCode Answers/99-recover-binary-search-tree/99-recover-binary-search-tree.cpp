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
    void fixBST(TreeNode* root,TreeNode* &first,TreeNode* &second,TreeNode* &prev)
    {
        if(root==NULL)
            return;
        fixBST(root->left,first,second,prev);
        
        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)
                first = prev;
            second = root;
        }
        prev=root;
        fixBST(root->right,first,second,prev);
    }
     void swapNodes(TreeNode* &first,TreeNode* &second)
    {    
        swap(first->val,second->val);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* f=NULL,*s=NULL,*p=NULL;
        fixBST(root,f,s,p);
        swapNodes(f,s);
    }
};