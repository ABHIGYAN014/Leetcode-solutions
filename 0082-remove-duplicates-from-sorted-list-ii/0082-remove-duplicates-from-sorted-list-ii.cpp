class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head) {
            bool isDuplicate = false;
            while (head->next && head->val == head->next->val) {
                isDuplicate = true;
                ListNode* duplicate = head->next;
                head->next = head->next->next;
                delete duplicate;
            }
            
            if (isDuplicate) { 
                prev->next = head->next;
                delete head;
            } else { 
                prev = prev->next;
            }
            
            head = prev->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
