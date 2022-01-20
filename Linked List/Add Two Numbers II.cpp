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
class Solution {
public:
    stack<int> convertToStack(ListNode *head) {
        stack<int> s;
        while (head) {
            s.push(head -> val);
            head = head -> next;
        }
        return s;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 = convertToStack(l1);
        stack<int> s2 = convertToStack(l2);
        ListNode *sum_list = new ListNode(0);
        ListNode *start_ptr = sum_list;
        int carry = 0, add, x = 0, y = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                x = s1.top();
                s1.pop();
            } else {
                x = 0;
            }
            if (!s2.empty()) {
                y = s2.top();
                s2.pop();
            } else {
                y = 0;
            }
            add = x + y + carry;
            carry = add / 10;
            ListNode *new_node = new ListNode(add % 10);
            if (start_ptr -> next == NULL) {
                start_ptr -> next = new_node;
            } else {
                new_node -> next = start_ptr -> next;
                start_ptr -> next = new_node;
            }
        }
        return sum_list -> next;
    }
};

/*
APPROACH:
=> Since the heads of the two inputs points at the most significant digit, we need to start adding the digits
from the end of the list
=> We will take two stakcs and insert the digits of linked lists
=> The top of both stacks will represent the least significant digit
=> Then we can just keep adding them and create the sum_list by adding the new node at the head because the output 
we will get is in the reverse
*/

/*
Time Complexity: O(n + m)
Space Complexity: O(2(n + m))
*/


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *next_node, *cur = head;
        while (cur != NULL) {
            next_node = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next_node;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0, add = 0;
        ListNode *sum_list = new ListNode();
        ListNode *start_ptr = sum_list;
        while (l1 || l2 || carry) {
            add = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry;
            carry = add / 10;
            ListNode *new_node = new ListNode(add % 10);
            if (start_ptr -> next == NULL) {
                start_ptr -> next = new_node;
            } else {
                new_node -> next = start_ptr -> next;
                start_ptr -> next = new_node;
            }
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }
        return sum_list -> next;
    }
};

/*
APPROACH:
=> Just reverse both lists and their digits
*/

/*
Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/
