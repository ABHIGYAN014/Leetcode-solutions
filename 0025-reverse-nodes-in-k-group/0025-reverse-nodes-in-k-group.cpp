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
    int length(ListNode*head)
    {
        int lengthh=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            lengthh++;
        }
        return lengthh;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        {
            return NULL;
        }
        int len=length(head);
        if(len<k)
        {
            return head;
        }
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*nextnode=curr->next;
        int count=0;
        while(count<k)
        {
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            count++;
        }
      if(nextnode!=NULL)
        {head->next=reverseKGroup(nextnode,k);
        }

        return prev;
    }
};