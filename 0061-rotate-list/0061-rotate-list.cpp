class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        // Find the length of the list
        ListNode* current = head;
        int length = 1;  // At least one node is there
        while (current->next) {
            current = current->next;
            length++;
        }
        
        // Make the list circular
        current->next = head;
        
        // Find the effective number of rotations
        k = k % length;
        int stepsToNewHead = length - k;
        
        // Find the new tail (which will be at position `stepsToNewHead - 1`)
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        
        // The new head will be the node after the new tail
        ListNode* newHead = newTail->next;
        
        // Break the circle
        newTail->next = nullptr;
        
        return newHead;
    }
};
