/*Problem Statement:
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

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
class Solution 
{
public:
    int len(ListNode* head)
    {
        int lent=0;
        while(head!=NULL)
        {
            lent++;
            head=head->next;
        }
        return lent;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int k = len(head)-n;
        ListNode* temp = dummy;
        while(k-->0)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return dummy->next;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)