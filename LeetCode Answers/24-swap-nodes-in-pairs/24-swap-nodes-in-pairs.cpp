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
    ListNode* swapPairs(ListNode* head) {
        ListNode* r=head;
        int i,n=numberOfNodes(head);
        vector<int> v;
        if(head==NULL)
            return head;
        while(r!=NULL)
        {
            v.push_back(r->val);
            r=r->next;
        }
        
        for(i=0;i<n-1;i=i+2)
        {
            swap(v[i],v[i+1]);
        }
        ListNode* newnode=new ListNode;
        ListNode* h = newnode;
        
        for(i=0;i<n;i++)
        {
            newnode->next= new ListNode(v[i]);
            newnode=newnode->next;
        }
        return h->next;
    }
    
    int numberOfNodes(ListNode* head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
};