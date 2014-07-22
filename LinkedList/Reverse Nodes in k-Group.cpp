/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || k == 1)
            return head;
        ListNode dummyNode (INT_MAX);
        ListNode * pre = & dummyNode;
        while(head)
        {
            ListNode * cur = head;
            int i = 0;
            while(cur)
            {
                ++i;
                if(i==k)
                    break;
                cur = cur->next;
            }
            if(i!=k)
            {
                pre->next = head;
                break;
            }
            else
            {
                ListNode * next = cur->next;
                ListNode * last = head;
                pre->next = reverse(head,cur->next);
		//Pay attention to fellowing 
                pre = last;
                head = next;
            }
        }
        return dummyNode.next;
    }
    
    ListNode * reverse(ListNode * head , ListNode * end)
    {
        if(head == NULL || head == end || head->next == end)
            return head;
        ListNode * pre = NULL;
        while(head != end)
        {
            ListNode * next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};