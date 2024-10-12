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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         // Create a dummy node to serve as the starting point of the merged list
        ListNode dummy;
        ListNode* tail = &dummy;  // Use 'tail' to build the merged list

        // Traverse both lists until one of them runs out of nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;  // Link the smaller node
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2;  // Link the smaller node
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move the tail to the new last node
        }

        // If any nodes are left in either list, append them to the merged list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the merged list starting from the node after the dummy
        return dummy.next;
    }
};