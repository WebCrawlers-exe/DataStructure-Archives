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
    TreeNode* sortedListToBST(vector<int>& nums,int start,int end)
    {
        if(end<start)
            return NULL;
        int mid = (start+end)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedListToBST(nums,start,mid-1);
        
        root->right = sortedListToBST(nums,mid+1,end);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedListToBST(nums,0,nums.size()-1);
        
        
    }
};