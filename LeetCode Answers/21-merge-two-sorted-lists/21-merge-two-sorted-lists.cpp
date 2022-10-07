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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* r1 = list1;
        ListNode* r2 = list2;
        vector<int> v;
        
        while(r1!=NULL)
        {
            v.push_back(r1->val);
            r1 = r1->next;
        }
        
        while(r2!=NULL)
        {
            v.push_back(r2->val);
            r2 = r2->next;
        }
        
        sort(v.begin(),v.end());
        
        ListNode* t = new ListNode(0);
        ListNode* op = t;
        
        for(int i=0;i<v.size();i++)
        {
            t->next = new ListNode(v[i]);
            t = t->next; 
        }
        return op->next;
    }
};