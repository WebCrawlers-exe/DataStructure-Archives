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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i;
        ListNode* r=head;
        ListNode* newnode=new ListNode;
        ListNode* t=newnode;
        vector<int> v;
        
        while(r!=NULL)
        {
            v.push_back(r->val);
            r=r->next;
        }
        reverse(v.begin()+left-1,v.begin()+right);
        for(i=0;i<v.size();i++)
        {
            ListNode* temp=new ListNode(v[i]);
            if(newnode==NULL)
                newnode=temp;
            else
            {
                newnode->next=temp;
                newnode=newnode->next;
            }
        }
        
        return t->next;
    }
};