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
    ListNode* partition(ListNode* head, int x) {
        ListNode* newnode1=new ListNode;
        ListNode* newnode2=new ListNode;
        
        ListNode* r= head;
        ListNode* t1= newnode1;
        ListNode* t2= newnode2;
        while(r!=NULL)
        {
            if(r->val<x)
            {
                newnode1->next=new ListNode(r->val);
                newnode1=newnode1->next;
            }
            else
            {
                newnode2->next=new ListNode(r->val);
                newnode2=newnode2->next;
            }
            r=r->next;
        }
        
        t2=t2->next;
        while(t2!=NULL)
        {
            newnode1->next=new ListNode(t2->val);
            newnode1=newnode1->next;
            t2=t2->next;
        }
        
        return t1->next;
    }
};