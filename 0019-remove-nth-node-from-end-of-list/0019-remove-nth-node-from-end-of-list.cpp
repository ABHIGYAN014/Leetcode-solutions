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
    int length(ListNode* head) {
        ListNode* temp = head;
        int lengthh = 0;
        while (temp) {
            temp = temp->next;
            lengthh++;
        }
        return lengthh; 
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = length(head);
        int indexToRemove = size - n; 

        if (indexToRemove == 0) {
            ListNode* newHead = head->next;
            delete head;   
            return newHead;
        }

        ListNode* temp = head;
        while (indexToRemove > 1) {
            temp = temp->next;
            indexToRemove--;
        }

        temp->next = temp->next->next; 
        return head;
    }
};
