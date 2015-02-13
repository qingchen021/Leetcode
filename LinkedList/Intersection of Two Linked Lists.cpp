/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J            
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int stepsA = 0, stepsB = 0;
        ListNode * head = headA;
        while(head)
        {
            stepsA++;
            head = head->next;
        }
        head = headB;
        while(head)
        {
            stepsB++;
            head = head->next;
        }
        ListNode * slow = NULL, * fast = NULL;
        int steps = 0;
        if(stepsA>stepsB)
        {
            slow = headB;
            fast = headA;
            steps = stepsA - stepsB;
        }
        else
        {
            slow = headA;
            fast = headB;
            steps = stepsB - stepsA;;
        }
        while(steps--)
        {
            fast = fast->next;
        }
        while(fast&&slow)
        {
            if(fast == slow)
                return fast;
            fast = fast->next;
            slow = slow ->next;
        }
        return NULL;
    }
};