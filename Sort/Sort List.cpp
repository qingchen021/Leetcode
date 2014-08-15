/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode * slow = head, *fast = head, *preSlow = NULL;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            preSlow = slow;
            slow = slow->next;
        }
        preSlow->next = NULL;
        ListNode * first = sortList(head);
        ListNode * last = sortList(slow);
        ListNode dummyNode(INT_MIN);
        ListNode * pre = &dummyNode;
        while (first&&last)
        {
            if (first->val<last->val)
            {
                pre->next = first;
                first = first->next;
            }
            else
            {
                pre->next = last;
                last = last->next;
            }
            pre = pre->next;
        }
        ListNode * left = NULL;
        if (first)
            left = first;
        if (last)
            left = last;
        if (left)
        {
            pre->next = left;
        }
        return dummyNode.next;
    }
};