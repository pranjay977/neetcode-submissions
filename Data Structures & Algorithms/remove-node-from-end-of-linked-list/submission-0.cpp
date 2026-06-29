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
    ListNode *st=head;
    ListNode *dummy=new ListNode(-1);
    dummy->next=head;
   ListNode *prev=dummy;
    while(head)
    {
    if(n==0) prev=prev->next;
    else if(n>0) n--;
    head=head->next;
    }
    prev->next=prev->next->next;
    return dummy->next;
    }
};
