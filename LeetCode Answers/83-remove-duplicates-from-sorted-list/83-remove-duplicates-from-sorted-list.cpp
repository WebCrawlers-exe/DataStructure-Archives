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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* r=head;
         ListNode* n=new ListNode;
        if(r==NULL)
            return head;
        
        while(r && r->next!=NULL)
        {
            if(r->val==r->next->val)
            {
                n=r;
                r->next=r->next->next;
                r=n;
            }
            else
                r=r->next;
        }
        return head;
    }
};