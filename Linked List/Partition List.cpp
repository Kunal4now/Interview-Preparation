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

// Two pass with one list
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *new_list = new ListNode(0);
        ListNode *ptr = head, *newPtr = new_list;
        while (ptr) {
            if (ptr -> val < x) {
                newPtr -> next = new ListNode(ptr -> val);
                newPtr = newPtr -> next;
            }
            ptr = ptr -> next;
        }
        ptr = head;
        while (ptr) {
            if (ptr -> val >= x) {
                newPtr -> next = new ListNode(ptr -> val);
                newPtr = newPtr -> next;
            }
            ptr = ptr -> next;
        }
        return new_list -> next;
    }
};

/*
Time Complexity: O(n + n)
Space Complexity: O(n)
*/

//Using values in a single list with one pass

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *new_list = new ListNode(0);
        ListNode *ptr = head;
        ListNode *smallPtr = new_list, *largePtr = NULL, *largeStart = NULL;
        while (ptr) {
            ListNode *new_node = new ListNode(ptr -> val);
            if (ptr -> val < x) {
                if (largeStart) {
                    new_node -> next = largeStart;
                    smallPtr -> next = new_node;
                    smallPtr = smallPtr -> next;
                }
                else {
                    smallPtr -> next = new_node;
                    smallPtr = smallPtr -> next;
                }
            }
            else {
                if (!largePtr) {
                    smallPtr -> next = new_node;
                    largePtr = smallPtr -> next;
                    largeStart = largePtr;
                }
                else {
                    largePtr -> next = new_node;
                    largePtr = largePtr -> next;
                }
            }
            ptr = ptr -> next;
        }
        return new_list -> next;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

// One pass with two lists
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessThanX = new ListNode(0);
        ListNode *greaterThanOrEqualToX = new ListNode(0);
        ListNode *ptr = head, *lessPtr = lessThanX, *greaterPtr = greaterThanOrEqualToX;
        while (ptr) {
            if (ptr -> val < x) {
                lessPtr -> next = new ListNode(ptr -> val);
                lessPtr = lessPtr -> next;
            }
            else {
                greaterPtr -> next = new ListNode(ptr -> val);
                greaterPtr = greaterPtr -> next;
            }
            ptr = ptr -> next;
        }
        lessPtr -> next = greaterThanOrEqualToX -> next;
        return lessThanX -> next;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

// Single pass with constant space
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessThanX = new ListNode(0);
        ListNode *greaterThanOrEqualToX = new ListNode(0);
        ListNode *ptr = head, *lessPtr = lessThanX, *greaterPtr = greaterThanOrEqualToX;
        while (ptr) {
            if (ptr -> val < x) {
                lessPtr -> next = ptr;
                lessPtr = lessPtr -> next;
            }
            else {
                greaterPtr -> next = ptr;
                greaterPtr = greaterPtr -> next;
            }
            ptr = ptr -> next;
        }
        greaterPtr -> next = NULL;
        lessPtr -> next = greaterThanOrEqualToX -> next;
        return lessThanX -> next;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
