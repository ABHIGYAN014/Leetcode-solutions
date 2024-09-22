class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: If the list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;

        // Perform the swap
        first->next = swapPairs(second->next); // Recursively call for the next pairs
        second->next = first;                    // Complete the swap

        return second; // Return the new head of the swapped pair
    }
};
