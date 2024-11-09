class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle edge case where the list is empty
        if (!head) return nullptr;
        
        ListNode* current = head;
        
        // Traverse through the list
        while (current && current->next) {
            // If the current node's value is the same as the next node's value
            if (current->val == current->next->val) {
                // Skip the next node (duplicate)
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }
        
        return head;
    }
};
