/* Problem Statement:
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/

class Solution {
public:
    ListNode* reverse(ListNode* temp)
    {
        if(temp==NULL || temp->next==NULL)
        {
            return temp;
        }
        ListNode* rest = reverse(temp->next);
        temp->next->next = temp;
        temp->next=NULL;
        return rest;
    }
    
    int len(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    
    void combine(ListNode* head1, ListNode* head2,int n)
    {
        
        n--;
        while(n-->0)
        {
            ListNode* actualnext = head1->next;
            head1->next = new ListNode(head2->val);
            head1->next->next = actualnext;
            head1 = head1->next->next;
            head2 = head2->next;
        }
    }

    
    void reorderList(ListNode* head) 
    {
        ListNode* temp = head;
        int n = len(temp);
        temp = head;
        for(int i=0;i<n/2;i++)
        {
            temp = temp->next;
        }
        ListNode* temp2= reverse(temp);
        temp = head;
        int carry = n%2;
        combine(temp,temp2,carry+n/2);
    }
};

// Time complexity: O(n)
// Space complexity: O(n)