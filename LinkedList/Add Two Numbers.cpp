/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * first = l1 , *second = l2;
        int carry = 0;
        ListNode dummy(0);
        ListNode * cur = &dummy;
        while(first && second)
        {
        	int num = first->val + second->val + carry;
        	if(num >= 10)
        	{
        		carry = 1;
        		num -= 10;
        	}
        	else
        	   carry = 0;
        	first->val = num;
        	cur->next = first;
        	cur = cur->next;
        	first = first->next;
        	second = second->next;
        }
        while(first)
        {
        	int num = first->val + carry;
        	if(num >= 10)
        	{
        		carry = 1;
        		num -= 10;
        	}
        	else
        	   carry = 0;
        	first->val = num;
        	cur->next = first;
        	cur = cur->next;
        	first = first->next;
        }
         while(second)
        {
        	int num = second->val + carry;
        	if(num >= 10)
        	{
        		carry = 1;
        		num -= 10;
        	}
        	else
        	   carry = 0;
        	second->val = num;
        	cur->next = second;
        	cur = cur->next;
        	second = second->next;
        }
        if(carry == 1)
        {
        	cur->next = new ListNode(1);
        }
        return dummy.next;
    }
};