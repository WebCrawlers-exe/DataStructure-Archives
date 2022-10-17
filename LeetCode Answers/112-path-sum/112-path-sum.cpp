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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // Base Case
          if(!root)
              return false;
         
              // Pre-caculation
              targetSum-=root->val;
        
           // For A Root Node
             if(!root->right&&!root->left)
                return targetSum==0?true:false;
        
         // Traverse Over Tree
        if(hasPathSum(root->left,targetSum)) return true;
        
        if(hasPathSum(root->right,targetSum)) return true; 
        
        return false; 
    }
};