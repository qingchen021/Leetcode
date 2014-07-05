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
        if(head==NULL||head->next==NULL)
            return head;
        ListNode * slow = head, * fast = head;
        while(fast->next&&fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;;
        }
        
        ListNode * tmp = slow->next;
        slow->next = NULL;
        ListNode * first = sortList(head);
        ListNode * second = sortList(tmp);
        ListNode dummyNode(INT_MIN);
        ListNode * pre = &dummyNode;
        while(first&&second)
        {
            if(first->val < second->val)
            {
                pre->next =first;
                first=first->next;
            }
            else
            {
                pre->next = second;
                second = second->next;
            }
            pre = pre->next;
        }
        if(first)
            pre->next = first;
        if(second)
            pre->next = second;
        return dummyNode.next;
    }
};