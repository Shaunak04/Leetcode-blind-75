/* Problem Statement:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
*/

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        ListNode* head=NULL;
        if(l1->val < l2->val)  
        { 
            head = l1; 
            l1 = l1->next; 
        }
        else
        {
            head = l2; 
            l2 = l2->next; 
        }
        ListNode* p = head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)   
            { 
                p->next = l1; 
                l1 = l1->next; 
            }
            else                   
            {
                p->next = l2;
                l2 = l2->next; 
            }
            p=p->next;
        }
        if(l1)  p->next=l1;
        else    p->next=l2;
        return head;
    }
};

// Time Compleixty: O(max(l1, l2))
// Space Complexity: O(1)