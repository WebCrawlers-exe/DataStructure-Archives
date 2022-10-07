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
bool fun(TreeNode* node,long l,long r){
        if(node == NULL)
            return true;
        
        if(node->val <= l || node->val >= r)
            return false;
        
        if(!fun(node->left, l , node->val))
            return false;
        if(!fun(node->right,node->val,r))
            return false;
        
        return true;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        bool ans = fun(root,LONG_MIN,LONG_MAX);
        return ans;
    }
};