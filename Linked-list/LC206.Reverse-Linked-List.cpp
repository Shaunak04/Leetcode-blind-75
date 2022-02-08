/* Problem Statement:
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

// RECURSIVE CODE: O(n*n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
  if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};

//ITERATIVE CODE: O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* curr = head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
