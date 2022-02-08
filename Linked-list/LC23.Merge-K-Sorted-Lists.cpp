/* Problem Statement:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
*/

class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head = l1->val <= l2->val ? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1,l2->next);
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return NULL;
        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++)
        {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }
};

// Time Complexity: O(n*k), n is number of linked list and k is the number of nodes in the linked lists
// Space Complexity: O(n*k)