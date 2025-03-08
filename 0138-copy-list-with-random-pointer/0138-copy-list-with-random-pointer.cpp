class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* newHead = head->next;
        Node* oldNode = head, *newNode = newHead;
        while (oldNode) {
            oldNode->next = oldNode->next->next;
            if (newNode->next) {
                newNode->next = newNode->next->next;
            }
            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }
};
