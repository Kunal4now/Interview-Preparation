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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        while (list1 and list2) {
            if (list1 -> val < list2 -> val) {
                ptr -> next = list1;
                ptr = list1;
                list1 = list1 -> next;
            }
            else {
                ptr -> next = list2;
                ptr = list2;
                list2 = list2 -> next;
            }
        }
        ptr -> next = (list1 ? list1 : list2);
        dummy = dummy -> next;
        return dummy;
    }
    ListNode* findMid(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL or head -> next == NULL) {
            return head;
        }
        
        ListNode *mid = findMid(head);
        
        ListNode *l = head;
        ListNode *r = mid -> next;
        mid -> next = NULL;

        return merge(sortList(l), sortList(r));
    }
};
