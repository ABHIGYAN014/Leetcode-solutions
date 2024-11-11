#include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a comparison function for the min-heap
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        
        // Create a priority queue (min-heap) using the comparison function
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Add the head of each list to the min-heap
        for (ListNode* list : lists) {
            if (list) minHeap.push(list);
        }
        
        // Dummy head for the merged list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        while (!minHeap.empty()) {
            // Extract the smallest element
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append it to the result list
            current->next = smallest;
            current = current->next;
            
            // If there’s a next node in this list, push it into the min-heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy->next;
    }
};
