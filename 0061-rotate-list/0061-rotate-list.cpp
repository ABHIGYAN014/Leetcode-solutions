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
    int lengthh(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int length = lengthh(head);
        int actualrotate = k % length;
        if (actualrotate == 0)
            return head;

        int lastnodepos = length - actualrotate - 1;
        ListNode* lastnode = head;
        for (int i = 0; i < lastnodepos; i++) {
            lastnode = lastnode->next;
        }

        ListNode* newhead = lastnode->next;
        lastnode->next = nullptr;

        ListNode* it = newhead;
        while (it->next) {
            it = it->next;
        }
        it->next = head;

        return newhead;
    }
};
