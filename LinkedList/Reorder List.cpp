/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL)
            return ;
        ListNode * oneStep = head, * twoStep = head;
        while(twoStep->next && twoStep->next->next)
        {
            oneStep = oneStep->next;
            twoStep=twoStep->next->next;
        }
        ListNode * firstHalf = head;
        ListNode * lastHalf = oneStep->next;
        oneStep->next = NULL;
        lastHalf = reverse(lastHalf,NULL);
        ListNode dummyNode(INT_MAX);
        ListNode * pre = & dummyNode;
        while(firstHalf)
        {
            pre->next = firstHalf;
            ListNode * tmp = firstHalf->next;
            firstHalf->next = lastHalf;
            pre = lastHalf;
            firstHalf = tmp;
            if(lastHalf!=NULL)
                lastHalf = lastHalf->next;
        }
    }
    
    ListNode * reverse(ListNode * head, ListNode * end)
    {
        if(head == NULL || head == end || head->next == end)
            return head;
        ListNode * pre = NULL, * cur = head;
        while(cur!=end)
        {
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};