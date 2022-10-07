/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* bst(vector<int> v,int start,int end)
    {
        if(start>end)
            return NULL;
        int mid = (start+end)/2;
        
        TreeNode* root = new TreeNode(v[mid]);
        
        root->left = bst(v,start,mid-1);
        
        root->right = bst(v,mid+1,end);
        
        return root;    
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        ListNode* r = head;
        
        while(r!=NULL)
        {
            v.push_back(r->val);
            r=r->next;
        }
        
        return bst(v,0,v.size()-1);
    }
};