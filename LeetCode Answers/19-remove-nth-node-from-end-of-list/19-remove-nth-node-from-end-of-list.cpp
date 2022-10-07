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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0,l=0;
        ListNode* r=head;
        ListNode* prev=NULL;
        
        while(r!=NULL)
        {
            l++;
            r=r->next;
        }
        r=head;
        
        if(head==NULL)
            return NULL;
        if(l==1)
        {
            return NULL;
        }
        while(i!=l-n)
        {
            prev=r;
            r=r->next;
            i++;
        }
        cout<<r->val;
        if(prev==NULL)
        {
            return head->next;
        }
        else
        {
            prev->next=r->next;
            r->next=NULL;
            delete(r);
            return head;
        }  
    }
};