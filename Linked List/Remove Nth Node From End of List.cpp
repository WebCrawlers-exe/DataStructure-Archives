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
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        if(count == 1 && n == 1) return NULL;
        if(count == n) return head->next;
        int i = 0;
        temp = head;
        while(i < count - n -1)
        {
            temp = temp->next;
            i++;
        }
        if(n == 1)
        {
            temp->next = NULL;
            return head;
        }
        temp->next = (temp->next)->next;
        return head;
        
    }
};
